#include "animal.h"

animal::animal(){};

animal::animal(int id, string apelido, string data_mon, string espec, char sexo, string data_nas){
    this->id = id;
    this->apelido = apelido;
    this->data_monitoramnto = data_mon;
    this->especie = espec;
    this->sexo = sexo;
    this->data_nascimento = data_nas;
}

int animal::getId() const{
    return this->id;
}

string animal::getApelido() const{
    return this->apelido;
}
string animal::getData_mon() const{
    return this->data_monitoramnto;
}

string animal::getEspecie() const{
    return this->especie;
}
        
char animal::getSexo() const{
    return this->sexo;
}

string animal::getData_nasc() const{
    return this->data_nascimento;
}

vector<historico> animal::getHistorico(){
    return this->hist;
}

historico animal::getHistoricoById(int id){
    return this->hist.at(id);
}

void animal::adicionarHistorico(historico h){
    hist.push_back(h);
}

void animal::printDadosAnimal(){
    cout << "Dados do Animal:" << endl;
    cout << "Id: " << getId() << endl;
    cout << "Apelido:" << getApelido() << endl;
    cout << "Espécie: " << getEspecie() << endl;
    cout << "Sexo: " << getSexo() << endl;
    if(getData_nasc().empty()){
        cout << "Data de Nascimento: Desconhecida" << endl;
    }
    else{
        cout << "Data de Nascimento: " << getData_nasc() << endl;
    }
    cout << "Início do Monitoramento: " << getData_mon() << endl;
    int tam_his = hist.size();
    if(tam_his > 0){
        cout << "Histórico do animal: " << endl;
        cout << endl;
        for (int i = 0; i < tam_his; i++)
        {
            cout << "Registro "<< i + 1 << endl;
            hist.at(i).imprimirHistorico();

        }
        
    } else{
        cout << "Esse animal ainda não possui histórico" << endl;
    }
}

void animal::salvarAnimal(ofstream& arquivo){
    arquivo << "Id do animal: " << id << endl;
    arquivo << "Apelido: " << apelido << endl;
    arquivo << "Data do inicio do monitoramento: " << data_monitoramnto << endl;
    arquivo << "Espécie: " << especie << endl;
    arquivo << "Sexo: " << sexo << endl;
    arquivo << "Data Nascimento: " << data_nascimento << endl;
    arquivo << "Históricos Registrados: " << hist.size() << endl;
    if (hist.size() > 0){
        for (int i = 0; i < hist.size(); i++)
        {
            arquivo << "---------------------------" << endl;
            arquivo << "Histórico " << i + 1 << endl;
            arquivo << "Data da avaliação: " << hist[i].getDataAvaliacao() << endl;
            arquivo << "Temperatura: " << hist[i].getTemperatura() << endl;
            arquivo << "Peso: " << hist[i].getPeso() << endl;
            arquivo << "Altura: " << hist[i].getAltura() << "cm" <<endl;
            if(hist[i].getAmostra()){
                arquivo << "Foi coletadada uma amostra" << endl;
            }
            else {
                arquivo << "Nenhuma amostra foi coletada" << endl;
            }
            arquivo << "Resultado do Exame: " << hist[i].getExame() << endl;
            
        }
        arquivo << "---------------------------" << endl;
    }
}