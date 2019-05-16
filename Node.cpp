#include "Node.h"
#include <iostream>
#include <math.h>
#include "Objeto.h"

Node::Node(Objeto valor)
{
    data = valor;
    next = NULL;
}

Node::~Node()
{

}
Objeto Node::getValor()
{
    return data;
}

void Node::setValor(Objeto valor)
{
    data = valor;
}

Node* Node::getProx()
{
    return next;
}
void Node::setProx(Node* valor)
{
    next = valor;
}