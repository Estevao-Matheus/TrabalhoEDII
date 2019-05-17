#ifndef TRABALHOEDII_NODE_H
#define TRABALHOEDII_NODE_H

#include <iostream>
#include <math.h>
#include "Objeto.h"

using namespace std;

class Node{
public:
    Node(Objeto valor);
    ~Node();
    Objeto getValor();
    void setValor(Objeto valor);
    Node* getProx();
    void setProx(Node* valor);

private:
    Objeto data;
    Node *next;
};

#endif
