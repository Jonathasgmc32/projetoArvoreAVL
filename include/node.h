#ifndef NODE_H
#define NODE_H

#include "animal.h"

class node{
    private:
        animal ani;
        node *dir, *esc;
        int altura;
};

#endif