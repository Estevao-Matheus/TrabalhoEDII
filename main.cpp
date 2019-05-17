#include <iostream>
#include "Objeto.h"
#include "LeituraArquivo.h"
#include "ListaEncadeada.h"
#include "HashEncadeado.h"
#include "Ordenacao.h"
#include <fstream>

using namespace std;

void Cenario1(){
    cout << "Cenário 1:" << endl;
    LeituraArquivo arquivo("ratings.csv");
    ofstream saida;
    saida.open("arquivos/saida_cenario_1.txt");
    if(! saida.good())
        return;
    else cout << "arquivo criado!" << endl;
    cout << "processando...";
    int tamVet;
    int* vet = arquivo.LerEntrada("entrada.txt", &tamVet);
    for(int i =0; i < tamVet; i++)
        saida << vet[i] << " ";
    saida << endl;
    for(int i = 0; i < tamVet; i++) {
        int numEntradas = vet[i];
        saida << "------------------------------------" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            float* resultados = new float[3];
            for(int i =0; i < 3; i++) {
                resultados[i] = 0;
            }
            Ordenacao::QuickSort(obj, numEntradas, resultados);
            saida << "vetor ordenado em: " << resultados[0] << endl;
            saida << "comparacoes: " << resultados[1] << endl;
            saida << "trocas: " << resultados[2] << endl;

            delete(obj);
        }
    }
    saida.close();
}

void Cenario2() {
    cout << "Cenário 2:" << endl;
    LeituraArquivo arquivo("ratings.csv");
    ofstream saida;
    saida.open("arquivos/saida_cenario_2.txt");
    if(! saida.good())
        return;
    else cout << "arquivo criado!" << endl;
    cout << "processando...";
    int tamVet;
    int *vet = arquivo.LerEntrada("entrada.txt", &tamVet);
    for(int i = 0; i < tamVet; i++)
        saida << vet[i] << " ";
    saida << endl;
    for(int i = 0; i < tamVet; i++) {
        int numEntradas = vet[i];
        float* resultados = new float[3];
        saida << "------------------------------------" << endl;
        for(int j = 0; j < 5; j++) {
            for(int i=0; i<3; i++)
                resultados[i] = 0;
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::QuickSort(obj, numEntradas, resultados);
            saida << "vetor ordenado em: " << resultados[0] << endl;
            saida << "comparacoes: " << resultados[1] << endl;
            saida << "trocas: " << resultados[2] << endl;
            delete(obj);
        }
          saida << "------------------------------------" << endl;
        for(int j = 0; j < 5; j++) {
           Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::QuickSortMediana(obj, numEntradas, resultados);
            saida << "vetor ordenado em: " << resultados[0] << endl;
            saida << "comparacoes: " << resultados[1] << endl;
            saida << "trocas: " << resultados[2] << endl;
            delete(obj);
        }
        saida << "------------------------------------" << endl;
        for(int j = 0; j < 5; j++) {
            Objeto* obj = arquivo.RandomRead(numEntradas);
            Ordenacao::quickInsertion(obj, 0, numEntradas, resultados);
            saida << "vetor ordenado em: " << resultados[0] << endl;
            saida << "comparacoes: " << resultados[1] << endl;
            saida << "trocas: " << resultados[2] << endl;
            delete(obj);
        }
    }
}

void Cenario3() {

}

int main()
{
    //HashEncadeado* hash = new HashEncadeado(10);

    //Objeto* o = new Objeto();

    //hash->InsereTabelaHash(*o, 10);
    //hash->ImprimeTabelaHash(10);
    cout << "job" << endl;

    Cenario2();



    return 0;
}