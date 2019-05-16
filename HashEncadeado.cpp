#include "HashEncadeado.h"
#include "Objeto.h"


HashEncadeado::HashEncadeado(int tam)
{
    tab = new ListaEncadeada[tam];
}

HashEncadeado::~HashEncadeado()
{
    delete(tab);
}

int HashEncadeado::RetornaIndice(Objeto valor, int tam)
{
    return valor.getUserID()%tam;
}

int HashEncadeado::buscaTabelaHash(Objeto valor, int tam)
{
    if(tab[RetornaIndice(valor, tam)].existeValor(valor))
    {
        return RetornaIndice(valor, tam);
    }
    return -1;
}

void HashEncadeado::InsereTabelaHash(Objeto valor, int tam)
{
    tab[RetornaIndice(valor,tam)].insereNode(valor);
}

void HashEncadeado::RemoveTabelaHash(Objeto valor, int tam)
{
    tab[RetornaIndice(valor,tam)].removeNode(valor);
}

void HashEncadeado::DeletaTabelaHash(int tam)
{
    for(int i=0; i<tam; i++)
    {
        tab[i].~ListaEncadeada();
    }
}

void HashEncadeado::ImprimeTabelaHash(int tam)
{
    cout << "imprimindo Tabela Hash:\n";
    for(int i=0; i<tam; i++)
    {
        cout << i << ")\t";
        tab[i].imprimiLista();
        cout << "\n";
    }
}