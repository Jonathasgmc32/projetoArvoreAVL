
#include "historico.h"

historico::historico(){}

historico::historico(string data_avaliacao, float peso, float temp, float altura, bool amostra, string exame){
    this->data_avaliacao = data_avaliacao;
    this->temperatura = temp;
    this->altura = altura;
    this->peso = peso;
    this->amostra_coletada = amostra;
    this->exame_fisico = exame;
    
}

string historico::getDataAvaliacao(){
    return this->data_avaliacao;
}

string historico::getExame(){
    return this->exame_fisico;
}

float historico::getAltura(){
    return this->altura;
}

float historico::getTemperatura(){
    return this->temperatura;
}

float historico::getPeso(){
    return this->peso;
}

bool historico::getAmostra(){
    return this->amostra_coletada;
}

void historico::imprimirHistorico(){
    cout << "-------------------------" << endl;
    cout << "Data de Avaliação: " << getDataAvaliacao() << endl;
    cout << "Altura:" << getAltura() << endl;
    cout << "Peso: " << fixed << setprecision(3) << getPeso() << endl;
    cout << "Temperatura: " << fixed << setprecision(0)<< getTemperatura() << "°C" << endl;
    if(getAmostra()){
        cout << "Uma Amostra foi coletada" << endl;
    }
    else{
        cout << "Nenhuma Amostra coletada" << endl;
    }
    cout << "Exame: " << getExame() << endl;
    cout << endl;
}