#include "Objeto.h"
#include <iostream>
#ifndef TRABALHOEDII_ORDENACAO_H
#define TRABALHOEDII_ORDENACAO_H


using namespace std;

class Ordenacao {
public:
    static void BubbleSort(Objeto* vet, int tamVet);
    static void SelectionSort(Objeto* vet, int tamVet);
    static void InsertionSort(Objeto* vet, int tamVet);
    static void QuickSort(Objeto* vet, int tamVet);
    static void QuickSortMediana(Objeto* vet, int tamVet);
    static void MergeSort(Objeto* vet, int esq, int dir);
    static void ShellSort(Objeto* vet, int tamVet);
    static void quickInsertion(Objeto* vet, int low, int high);

private:
    static void Intercala(Objeto *vet, int inicio ,int meio ,int fim);
    static int Particiona(Objeto *vet, int inicio, int fim, int pivot);
    static void Troca(Objeto *vet, int i, int j);
    static int MediaDe3(Objeto *vet, int inicio, int fim);
    static void troca(int *xp, int *yp);

    static void AuxQuickSort(Objeto *vet, int inicio, int fim);
    static void AuxQuickSortMediana(Objeto *vet, int inicio, int fim);
    static void AuxMergeSort(Objeto *vet, int inicio, int fim);
    static void quickInsertionAux(Objeto* vet, int low, int high);
    static void insertionSortAux (Objeto * vet, int low, int high);
};


#endif //TRABALHOEDII_ORDENACAO_H
