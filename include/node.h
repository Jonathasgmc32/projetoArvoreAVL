#ifndef NODE_H
#define NODE_H

#include "animal.h"

class node{
    private:
        animal ani;
        node *esc, *dir;
        int altura;

    public:
        node();
        node(animal a);
        animal getAnimal();
        node* getEsc();
        node* getDir();
        void setEsc(node *novoNo);
        void setDir(node *novoNo);
        void setAnimal(animal novoAni);
};

#endif