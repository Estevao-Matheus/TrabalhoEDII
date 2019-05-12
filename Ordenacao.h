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
    void QuickSortMediana(Objeto* vet, int tamVet);
    void MergeSort(Objeto* vet, int tamVet);


private:
    void Intercala(Objeto *vet, int inicio ,int meio ,int fim);
    int Particiona(Objeto *vet, int inicio, int fim, int pivot);
    void Troca(Objeto *vet, int i, int j);
    int MediaDe3(Objeto *vet, int inicio, int fim);

    void AuxQuickSort(Objeto *vet, int inicio, int fim);
    void AuxQuickSortMediana(Objeto *vet, int inicio, int fim);
    void AuxMergeSort(Objeto *vet, int inicio, int fim);
};


#endif //TRABALHOEDII_ORDENACAO_H
