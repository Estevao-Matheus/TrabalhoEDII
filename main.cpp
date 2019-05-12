#include <iostream>
#include "Objeto.h"
#include "LeituraArquivo.h"
#include "Ordenacao.h"

using namespace std;

int main() {
    const int TAM_VETOR = 10;
    Objeto *obj;

    LeituraArquivo arquivo("ratings.csv");
    obj = arquivo.RandomRead(TAM_VETOR);
    Ordenacao o;
    o.QuickSortMediana(obj, TAM_VETOR);

    for (int i = 0; i < TAM_VETOR; i++)
        obj[i].Imprimi();
}