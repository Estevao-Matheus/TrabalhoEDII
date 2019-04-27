#include <iostream>
#include "Objeto.h"
#include "LeituraArquivo.h"
#include "Ordenacao.h"

using namespace std;

int main() {

    const int TAM_VETOR = 100;
    Objeto *obj;

    LeituraArquivo entrada;
    obj = entrada.RandomRead(TAM_VETOR, "ratings.csv");
    Ordenacao o;
    o.BubbleSort(obj, TAM_VETOR);

    int vetorTeste[] = {12, 44, 32, 76, 78, 87, 563, 203, 209, 3, 34, 34, 3, 94, 1, 4, 16, 9, 53, 400};
    o.mergesort(vetorTeste, 0, 20);
    for(int i = 0; i<20; i++) {
        cout << vetorTeste[i] << ", ";
    }

    for (int i = 0; i < TAM_VETOR; i++)
        obj[i].Imprimi();
}