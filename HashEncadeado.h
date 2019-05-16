#ifndef TRABALHOEDII_HASHENCADEADO_H
#define TRABALHOEDII_HASHENCADEADO_H
#include <iostream>
#include "ListaEncadeada.h"
#include "OBjeto.h"

using namespace std;

class HashEncadeado {
public:
    HashEncadeado(int tam);
    ~HashEncadeado();

    int RetornaIndice(Objeto valor, int tam);
    int buscaTabelaHash(Objeto valor, int tam);
    void InsereTabelaHash(Objeto valor, int tam);
    void RemoveTabelaHash(Objeto valor, int tam);
    void DeletaTabelaHash(int tam);
    void ImprimeTabelaHash(int tam);

private:
    ListaEncadeada* tab;
};


#endif //TRABALHOEDII_HASHENCADEADO_H
