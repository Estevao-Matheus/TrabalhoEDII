#ifndef TRABALHOEDII_LISTAENCADEADA_H
#define TRABALHOEDII_LISTAENCADEADA_H
#include "Node.h"

using namespace std;

class ListaEncadeada
{
public:
    ListaEncadeada();
    ~ListaEncadeada();
    void insereNode(Objeto valor);
    void removeNode(Objeto valor);
    bool vazia();
    void imprimiLista();
    bool existeValor(Objeto valor);


private:
    Node *primeiro;
};

#endif // LISTAENCADEADA_H