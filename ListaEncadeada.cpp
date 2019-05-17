#include "ListaEncadeada.h"
#include <iostream>
#include <math.h>

ListaEncadeada::ListaEncadeada()
{
    primeiro = NULL;
}

ListaEncadeada::~ListaEncadeada()
{
    if(!vazia())
    {
        Node* aux = primeiro->getProx();
        while(primeiro->getProx()!=NULL)
        {
            delete primeiro;
            primeiro = aux;
            aux=primeiro->getProx();
        }
        delete primeiro;
        primeiro = NULL;
    }
}

bool ListaEncadeada::vazia()
{
    if(primeiro == NULL)
        return true;
    return false;
}

void ListaEncadeada::insereNode(Objeto valor)
{
    Node* newNode = new Node(valor);
    if(vazia())
        primeiro = newNode;
    else
    {
        Node* aux = primeiro;
        while(aux->getProx()!=NULL)
        {
            aux = aux->getProx();
        }
        aux->setProx(newNode);
    }
}
void ListaEncadeada::removeNode(Objeto valor)
{
    if(!vazia())
    {
        Node* aux = primeiro;
        if(aux->getValor().getUserID()==valor.getUserID()) //Caso em que eh deletado o primeiro elemento
        {
            primeiro = primeiro->getProx();
            delete aux;
            primeiro = NULL;
        }
        else
        {
            while(aux->getProx()!=NULL)
            {
                if((aux->getProx())->getValor().getUserID() == valor.getUserID())
                {
                    Node *aux2 = aux->getProx();
                    aux->setProx(aux2->getProx());
                    delete aux2;
                    break;
                }
                aux = aux->getProx();
            }
        }
    }
}

bool ListaEncadeada::existeValor(Objeto valor)
{
    if(!vazia())
    {
        Node* aux = primeiro;
        while(aux!=NULL)
        {
            if(aux->getValor().getUserID()==valor.getUserID())
                return true;
        }
    }
    return false;
}

void ListaEncadeada::imprimiLista()
{
    cout<<" ";
    if(!vazia())
    {
        Node* aux = primeiro;
        while(aux!=NULL)
        {
            aux->getValor().Imprimi();
            aux = aux->getProx();
        }
    }
    cout<<"NULL";
}