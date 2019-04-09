#include "Objeto.h"
#include "Ordenacao.h"

Ordenacao::Ordenacao() { }

Ordenacao::~Ordenacao() { }

void Ordenacao::BubbleSort(Objeto *vet, int tamVet)
{
    bool troca = true;
    for(int i =0; i <tamVet-1 && troca; i++){
        troca = false;
        for(int j = 0; j<tamVet-1-i; j++){
            if(vet[j].getUserID()>vet[j+1].getUserID()){
                Objeto aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                troca = true;
            }
        }
    }
}

void Ordenacao::SelectionSort(Objeto *vet, int tamVet)
{
    int menor = 0;
    for(int i =0; i <tamVet-1; i++){
        menor = i;
        for(int j = i+1; j<tamVet; j++){
            if(vet[menor].getUserID() > vet[j].getUserID()){
                menor = j;
            }
        }
        Objeto aux = vet[menor];
        vet[menor] = vet[i];
        vet[i] = aux;
    }
}

void Ordenacao::InsertionSort(Objeto *vet, int tamVet)
{
    Objeto pivo(0, 0, 0, 0);
    int j = 0;
    for(int i = 1; i < tamVet; i ++){
        pivo = vet[i];
        j = i-1;
        while(j >= 0 && vet[j].getUserID() > pivo.getUserID()){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = pivo;
    }
}
