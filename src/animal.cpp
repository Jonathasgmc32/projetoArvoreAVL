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

vector<historico> animal::getHistorico() const{
    return this->hist;
}

historico animal::getHistoricoById(int id) const{
    return this->hist[id];
}

void animal::printDadosAnimal() const{
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
    //adicionar imprimirHistorico() aqui depois que implementar
}