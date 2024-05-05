#ifndef ARVORE_H
#define ARVORE_H
#include "node.h"

class arvore{
    private:
        node *raiz;
    public:
        arvore();
        bool arvoreVazia();
        int getAltura(node *raiz);
        int getBalancoNo(node *no);
        node* balancoDireita(node *p);
        node* balancoEsquerda(node *p);
        node* inserirNo(node *raiz, node *novoNo);
        node* buscaNo(node *raiz, int id);
        node* valorminimo(node* no);
        node* deletarNo(node* raiz, int id);
        
    };

#endif