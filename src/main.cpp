#include <iostream>
#include <fstream>
#include "arvore.h"

int main(int argc, char* argv[]){
    arvore fauna;
    node *novoNo  = new node();
    int option, valor, linha;

    if(argc > 1){
        std::ifstream arquivo(argv[1]);
        if (arquivo.is_open()) {
            int linhasLidas = 0;
            int qtdHistoricos, qtdAnimais, id;
            string linha, apelido, data_mon, especie, data_nas, data_aval, exame;
            char sexo;
            float altura, peso, temperatura;
            bool amostra;
            if(getline(arquivo, linha)){
                qtdAnimais = stoi(linha);
                for (int i = 0; i < qtdAnimais; i++)
                {
                    getline(arquivo, linha);
                    id = stoi(linha);
                    getline(arquivo, apelido);
                    getline(arquivo,data_mon);
                    getline(arquivo, especie);
                    getline(arquivo, linha);
                    sexo = linha[0];
                    getline(arquivo, data_nas);
                    getline(arquivo, linha);
                    qtdHistoricos = stoi(linha);
                    novoNo = fauna.buscaNo(fauna.getRaiz(), id);
                    if(novoNo == NULL){
                        animal a = animal(id, apelido, data_mon, especie, sexo, data_nas);
                        node *no2 = new node();
                        no2->setAnimal(a);
                        fauna.setRaiz(fauna.inserirNo(fauna.getRaiz(), no2));
                        for(int j = 0; j < qtdHistoricos; j++){
                            getline(arquivo,data_aval);
                            getline(arquivo, linha);
                            altura = stof(linha);
                            getline(arquivo, linha);
                            peso = stof(linha);
                            getline(arquivo, linha);
                            temperatura = stof(linha);
                            getline(arquivo, linha);
                            amostra = stoi(linha);
                            getline(arquivo, exame);
                            historico h = historico(data_aval, peso, temperatura, altura, amostra, exame);
                            no2->ajustaHistorico(h);
                        }
                    } else{
                        for (int j = 0; j < qtdHistoricos * 6; j++)
                        {
                            getline(arquivo, linha);
                        }
                        
                    }
                }
                
            }
            arquivo.close();
        } else {
            std::cout << "Erro ao abrir o arquivo inicial de animais" << endl;
        }
    }
    
    cout << "Boas vindas ao sistema de fauna do parque das Dunas" << endl;
    do {
        cout << "O que você deseja fazer?" << endl;
        cout << "1. Inserir Animal" << endl;
        cout << "2. Buscar Animal" << endl;
        cout << "3. Remover Animal" << endl;
        cout << "4. Adicionar histórico a um animal" << endl;
        cout << "5. Salvar dados em arquivo" << endl;
        cout << "0. Sair do programa" << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            cout << "Saindo do Sistema..." << endl;
            break;
        case 1:
            cout << "Insira o id do Animal:" << endl;
            cin >> valor;
            cin.ignore();
            novoNo = fauna.buscaNo(fauna.getRaiz(), valor);
            if(novoNo != NULL){
                cout << "Erro! Esse id já existe!" << endl;
            } else{
                string apelido, data_mon, espec, data_nas;
                char sexo;
                cout << "Insira o apelido do animal" << endl;
                getline(cin, apelido);
                cout << "Insira a data de início de monitoramento" << endl;
                getline(cin, data_mon);
                cout << "Insira a espécie" << endl;
                getline(cin, espec);
                cout << "Insira a data de nascimento (deixar vazio se desconhecida)" << endl;
                getline(cin, data_nas);
                cout << "Insira o sexo do animal: Macho (M)/ Fêmea (F)" << endl;
                cin >> sexo;
                animal a = animal(valor, apelido, data_mon, espec, sexo, data_nas);
                node *no2 = new node();
                no2->setAnimal(a);
                fauna.setRaiz(fauna.inserirNo(fauna.getRaiz(), no2));
                cout << "Animal inserido com sucesso!" << endl;
                cout<<endl;
            }
            break;
        case 2:
            cout << "Insira o id do Animal:" << endl;
            cin >> valor;
            novoNo = fauna.buscaNo(fauna.getRaiz(), valor);
            if(novoNo != NULL){
                novoNo->getAnimal().printDadosAnimal();
            }
            else{
                cout << "Animal não encontrado" << endl;
            }
            break;
        case 3:
            cout << "Insira o id do Animal:" << endl;
            cin >> valor;
            novoNo = fauna.buscaNo(fauna.getRaiz(), valor);
            if(novoNo !=NULL){
                fauna.setRaiz(fauna.deletarNo(fauna.getRaiz(), valor));
                cout << "Animal removido com sucesso!" << endl;
            } else{
                cout << "Animal não encontrado" << endl;
            }
            cout << endl;
            break;
        case 4:
            
            cout << "Insira o id do Animal:" << endl;
            cin >> valor;
            cin.ignore();
            novoNo = fauna.buscaNo(fauna.getRaiz(), valor);
            if(novoNo !=NULL){
                string data_ava, exame, amostra;
                float temp, peso, altura;
                bool resposta_amostra;
                cout << "Insira a data de avaliação do animal:" << endl;
                getline(cin, data_ava);
                cout << "Insira a altura em CM:" << endl;
                cin >> altura;
                cout << "Insira o peso:" << endl;
                cin >> peso;
                cout << "Insira a temperatura em °C:" << endl;
                cin >> temp;
                cout << "Foi coletada amostra do animal? (S ou N)" << endl;
                cin >> amostra;
                cin.ignore();
                cout << "Qual foi o resultado do exame físico?" << endl;
                getline(cin, exame);

                if(amostra == "S" || amostra == "s" || amostra == "SIM" || amostra == "Sim")
                    resposta_amostra = true;
                else
                    resposta_amostra = false;

                historico h = historico(data_ava, peso, temp, altura, resposta_amostra, exame);
                novoNo->ajustaHistorico(h);

                cout << "Historico adicionado ao animal com sucesso" << endl;
            } else{
                cout << "Animal não encontrado" << endl;
            }
            cout << endl;
            break;
        case 5:
            fauna.salvarArvore(fauna.getRaiz(), "DadosAnimais.txt");
            
            break;
        case 9: 
            fauna.print2D(fauna.getRaiz(), 5);
            cout << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    } while (option !=0);
    return 0;
}