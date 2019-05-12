#include <iostream>
#include "Objeto.h"
#include "LeituraArquivo.h"
#include "Ordenacao.h"

using namespace std;

int main() {
    const int TAM_VETOR = 10;
    Objeto *obj;

    LeituraArquivo entrada;
    obj = entrada.RandomRead(TAM_VETOR, "ratings.csv");
    Ordenacao o;
    o.QuickSortMediana(obj, TAM_VETOR);

    for (int i = 0; i < TAM_VETOR; i++)
        obj[i].Imprimi();
}