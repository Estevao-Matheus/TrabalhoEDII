#include <iostream>
#include "Objeto.h"
#include "LeituraArquivo.h"
#include "Ordenacao.h"

using namespace std;

int main() {
    const int TAM_VETOR = 500000;
    LeituraArquivo arquivo("ratings.csv");
    Objeto *obj = arquivo.RandomRead(TAM_VETOR);
    Ordenacao::QuickSort(obj, TAM_VETOR);


    for (int i = 0; i < TAM_VETOR; i++)
        obj[i].Imprimi();
}