#include <iostream>
#include "arvore.h"

int main(){
    arvore fauna;
    int option, valor;
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

        node *novoNo  = new node();

        switch (option)
        {
        case 0:
            cout << "Saindo do Sistema..." << endl;
            break;
        case 1:
            cout << "Insira o id do Animal:" << endl;
            cin >> valor;
            if(fauna.existeNo(fauna.getRaiz(),valor)){
                cout << "Erro! Esse id já existe!" << endl;
            } else{
                string apelido, data_mon, espec, data_nas;
                char sexo;
                cout << "Insira o apelido do animal" << endl;
                cin >> apelido;
                cout << "Insira a data de início de monitoramento" << endl;
                cin >> data_mon;
                cout << "Insira a espécie" << endl;
                cin >> espec;
                cout << "Insira a data de nascimento (deixar vazio se desconhecida)" << endl;
                cin >> data_nas;
                cout << "Insira o sexo do animal: Macho (M)/ Fêmea (F)" << endl;
                cin >> sexo;
                animal a = animal(valor, apelido, data_mon, espec, sexo, data_nas);
                novoNo->setAnimal(a);
                fauna.setRaiz(fauna.inserirNo(fauna.getRaiz(), novoNo));
                cout << "Animal iserido com sucesso!" << endl;
                cout<<endl;
            }
            break;
        case 2:
            cout << "Insira o id do Animal:" << endl;
            cin >> valor;
            if(fauna.existeNo(fauna.getRaiz(),valor)){
                fauna.buscaNo(fauna.getRaiz(), valor)->getAnimal().printDadosAnimal();
            }
            else{
                cout << "Animal não encontrado" << endl;
            }
            break;
        case 3:
            cout << "Insira o id do Animal:" << endl;
            cin >> valor;
            if(fauna.existeNo(fauna.getRaiz(),valor)){
                fauna.setRaiz(fauna.deletarNo(fauna.getRaiz(), valor));
                cout << "Animal removido com sucesso!" << endl;
            } else{
                cout << "Animal não encontrado" << endl;
            }
            cout << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    } while (option !=0);
    return 0;
}