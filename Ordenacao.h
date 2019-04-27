#include "Objeto.h"
#include <iostream>
#ifndef TRABALHOEDII_ORDENACAO_H
#define TRABALHOEDII_ORDENACAO_H


using namespace std;

class Ordenacao {
public:
    Ordenacao();
    ~Ordenacao();

    void BubbleSort(Objeto* vet, int tamVet);
    void SelectionSort(Objeto* vet, int tamVet);
    void InsertionSort(Objeto* vet, int tamVet);
    void QuickSort(Objeto* vet, int tamVet);
    int mergesort(int* vetor, int inicio, int fim);
    void intercala(int inicio_vet,int inicio_vet2,int fim_vet,int vet[]);
};


#endif //TRABALHOEDII_ORDENACAO_H
