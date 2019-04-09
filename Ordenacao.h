#include "Objeto.h"
#ifndef TRABALHOEDII_ORDENACAO_H
#define TRABALHOEDII_ORDENACAO_H


class Ordenacao {
public:
    Ordenacao();
    ~Ordenacao();

    void BubbleSort(Objeto* vet, int tamVet);
    void SelectionSort(Objeto* vet, int tamVet);
    void InsertionSort(Objeto* vet, int tamVet);
};


#endif //TRABALHOEDII_ORDENACAO_H
