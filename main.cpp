#include <iostream>
#include "Objeto.h"
#include "LeituraArquivo.h"
#include "ListaEncadeada.h"
#include "HashEncadeado.h"
#include "Ordenacao.h"

using namespace std;

void Cenario1(){
    cout << "Cenário 1:" << endl;
    LeituraArquivo arquivo("ratings.csv");
    int tamVet;
    int* vet = arquivo.LerEntrada("entrada.txt", &tamVet);
    for(int i =0; i < tamVet; i++)
        cout << vet[i] << " ";
    cout << endl;
    for(int i = 0; i < tamVet; i++) {
        int numEntradas = vet[i];
        cout << "------------------------------------" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::QuickSort(obj, numEntradas);
            delete(obj);
        }
    }
}

void Cenario2() {
    cout << "Cenário 2:" << endl;
    LeituraArquivo arquivo("ratings.csv");
    int tamVet;
    int *vet = arquivo.LerEntrada("entrada.txt", &tamVet);
    for(int i = 0; i < tamVet; i++)
        cout << vet[i] << " ";
    cout << endl;
    for(int i = 0; i < tamVet; i++) {
        int numEntradas = vet[i];
        cout << "------------------------------------" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::QuickSort(obj, numEntradas);
            delete(obj);
        }
        cout << "-----" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::QuickSortMediana(obj, numEntradas);
            delete(obj);
        }
        cout << "-----" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::quickInsertion(obj, 0, numEntradas);
            delete(obj);
        }
    }
}
void Cenario3() {
    cout << "Cenário 3:" << endl;
    LeituraArquivo arquivo("ratings.csv");
    int tamVet;
    int *vet = arquivo.LerEntrada("entrada.txt", &tamVet);
    for(int i = 0; i < tamVet; i++)
        cout << vet[i] << " ";
    cout << endl;
    for(int i = 0; i < tamVet; i++) {
        int numEntradas = vet[i];
        cout << "------------------------------------" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::QuickSort(obj, numEntradas);
            delete(obj);
        }
        cout << "-----" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::QuickSortMediana(obj, numEntradas);
            delete(obj);
        }
        cout << "-----" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::quickInsertion(obj, 0, numEntradas);
            delete(obj);
        }
        cout << "-----" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::BubbleSort(obj, numEntradas);
            delete(obj);
        }
        cout << "-----" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::SelectionSort(obj,numEntradas);
            delete(obj);
        }
        cout << "-----" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::InsertionSort(obj, numEntradas);
            delete(obj);
        }
        cout << "-----" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::MergeSort(obj, 0, numEntradas);
            delete(obj);
        }
        cout << "-----" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::ShellSort(obj,numEntradas);
            delete(obj);
        }
    }
}

int main()
{
    //HashEncadeado* hash = new HashEncadeado(10);

    //Objeto* o = new Objeto();

    //hash->InsereTabelaHash(*o, 10);
    //hash->ImprimeTabelaHash(10);

    Cenario2();



    return 0;
}