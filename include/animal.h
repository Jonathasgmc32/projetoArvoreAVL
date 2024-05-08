#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <vector>
#include "historico.h"
using namespace std;

class animal{
    private:
        int id;
        string apelido;
        string data_monitoramnto; 
        string especie;
        char sexo;
        string data_nascimento;
        std::vector<historico> hist;
        public:
        animal();
        animal(int id, string apelido, string data_mon, string espec, char sexo, string data_nas);
        int getId() const;
        string getApelido() const;
        string getData_mon() const;
        string getEspecie() const;
        char getSexo() const;
        string getData_nasc() const;
        vector<historico> getHistorico();
        historico getHistoricoById(int id);
        void printDadosAnimal();
        void adicionarHistorico(historico h);
};

#endif