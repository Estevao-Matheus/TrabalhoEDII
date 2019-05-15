#include <iostream>
#include "Objeto.h"
#include "LeituraArquivo.h"
#include "Ordenacao.h"

using namespace std;

int main() {

    return 0;
}

void cenario1(){
    LeituraArquivo arquivo("ratings.csv");
    int tamVet;
    cout << "Cenário 1" << endl;
    int* vet = arquivo.LerEntrada("entrada.txt", &tamVet);
    int i;
    for(i = 0; i < tamVet; i++) {
        cout << "------------------------------------" << endl;
        for(int numConjunto = 0; numConjunto < 5; numConjunto++) {
            // executa cenário 1
            Objeto* obj;
            obj = arquivo.RandomRead(vet[i]);
            Ordenacao::QuickSort(obj, vet[i]);
            delete(obj);
            //escrever desempenho
        }
    }
}