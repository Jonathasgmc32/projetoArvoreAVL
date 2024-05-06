#include "node.h"

node::node(){
    this->esc = NULL;
    this->dir = NULL;
}

node::node(animal a){
    this->ani = a;
    this->esc = NULL;
    this->dir = NULL;
}

animal node::getAnimal(){
    return this->ani;
}

node* node::getDir(){
    return this->dir;
}

node* node::getEsc(){
    return this->esc;
}

void node::setEsc(node *novoNo){
    this->esc = novoNo;
}

void node::setDir(node *novoNo){
    this->dir = novoNo;
}

void node::setAnimal(animal novoAni){
    this->ani = novoAni;
}