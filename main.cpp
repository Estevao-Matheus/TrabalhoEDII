#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void bubbleSort(int* v, int n)
{
    bool troca = true;
    for(int i =0; i <n-1 && troca; i++){
        troca = false;
        for(int j = 0; j<n-1-i; j++){
            if(v[j]>v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                troca = true;
            }
        }
    }

}

void selectionSort(int* v, int n)
{
    int menor = 0;
    for(int i =0; i <n-1; i++){
        menor = i;
        for(int j = i+1; j<n; j++){
            if(v[menor]>v[j]){
                menor = j;
            }
        }
        int aux = v[menor];
        v[menor] = v[i];
        v[i] = aux;
    }
}

void insertionSort(int* v, int n)
{
    int pivo = 0, j = 0;
    for(int i = 1; i < n; i ++){
        pivo = v[i];
        j = i-1;
        while(j >= 0 && v[j]>pivo){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = pivo;
    }
}

void troca(int* vet, int i, int j)
{
    int aux = 0;
    aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}
int mediana(int *vet, int k, int tam)
{
    int aux[k] = {0};
    srand(time(NULL));
    for(int i = 0; i < tam; i++)
    {
        aux[i] = rand()%tam;
    }
    insertionSort(vet, k);
    if(k%2)
    {
        int med = (int)(k+1)/2;
        return vet[med];
    }
    else
    {
        int meio = (int)k/2;
        int med = (int)(vet[meio] + vet[meio-1])/2;
        return vet[med];
    }
}
/*
    Essa funcao pega o ultimo elemento como pivô, coloca o pivô na sua posição correta
    no vetor ordenado, e coloca todos os menores que o pivô à esquerda do pivô e todos os maiores à direita.
*/
int particiona (int vet[], int low, int high, int pivot)
{

    int i = (low - 1);  // Indice do menor elemento

    for (int j = low; j <= (high - 1); j++)
    {
        // Se o elemento atual é menor ou
        // igual ao pivot
        if (vet[j] <= pivot)
        {
            i++;    // incrementa indice do elemento menor
            troca(vet, i, j);
        }
    }
    troca(vet, i+1, high);
    return (i + 1);
}

/* low  --> indice do começo,  high  --> indice do fim */
void quickSort(int vet[], int low, int high)
{
    if (low < high)
    {
        /* pi é o índice de particionamento, vet[pi] está agora no lugar certo */
        int pi = particiona(vet, low, high, vet[high]);

        quickSort(vet, low, pi - 1);  // Antes do pi
        quickSort(vet, pi + 1, high); // Depois do pi
    }
}

void quickSortMediana(int vet[], int low, int high, int kMediana)
{
    if (low < high)
    {
        if(kMediana > high)
        {
            int pi = particiona(vet, low, high, vet[high]);
            quickSort(vet, low, pi - 1);  // Antes do pi
            quickSort(vet, pi + 1, high); // Depois do pi
        }
        else
        {
            int med = mediana(vet, kMediana, high+1);
            /* pi é o índice de particionamento, vet[pi] está agora no lugar certo */
            int pi = particiona(vet, low, high, med);
            quickSortMediana(vet, low, pi - 1, kMediana);  // Antes do pi
            quickSortMediana(vet, pi + 1, high, kMediana); // Depois do pi
        }

    }
}

int parse(string str)
{
    stringstream s(str);
    string sout;
    int ultimo = 0;
//    getline(s, sout, ',');
//    int valor = atoi(sout.c_str());
//    cout << valor;
    while(getline(s, sout, ','))
    {
        int valor = atoi(sout.c_str());
        //cout << ", " << valor;
        ultimo = valor;
    }
    return ultimo;

}

void randomRead(int qtdLinha)
{
    ifstream arq;
    arq.open("ratings.csv");
    arq.seekg(0, ios::end);
    int tamanho = arq.tellg();
    srand(time(NULL));
    int aleatorio = rand()%tamanho;
    arq.seekg(aleatorio, ios::beg);
    string strAux;
    getline(arq, strAux, '\n');//TRATAR A EXCE�AO DE CASO O CURSOR PARE NA ULTIMA LINHA
    int cont = 0;
    if(arq.is_open()) {
        string str;
        int *vetor = new int[qtdLinha];
        while (cont < qtdLinha) {
            if (!arq.eof()) {//PROVIS�RIO, TEMOS QUE VERIFICAR SE FUNCIONA MESMO
                cont++;
                cout << "teste: " << cont << endl;
                getline(arq, str);
                vetor[cont - 1] = parse(str);
                //cout << endl;
            }
        }
        insertionSort(vetor, cont);
    }else
    {
        cout << "Erro, arquivo nao pode ser aberto" << endl;
    }
    arq.close();
    cout << "Numero de linhas:" << cont << endl;
}

int main()
{

    int vet[] = {12, 8, 15, 1, 22, 9, 6, 14, 9, 10, 423, 221, 441, 12, 3, 4, 3, 71, 846, 21};
    quickSortMediana(vet,0,20, 5);
    for(int k = 0; k < 20; k++)
    {
        cout << vet[k] << ", ";
    }

//    ifstream arq;
//    arq.open("ratings.csv");
//    int cont = 0;
//    if(arq.is_open())
//    {
//        string str;
//        int valor = 0;
//        while(!arq.eof())
//        {
//            cont++;
//            if(cont != 1)
//            {
//                cout << "teste: " << cont << endl;
//                getline(arq, str);
//                valor = parse(str);
//                //cout << endl;
//            }
//
//        }
//        cout << valor << endl;
//    }
//    else
//    {
//        cout << "Erro, arquivo nao pode ser aberto" << endl;
//    }
//    arq.close();
//    cout << "Numero de linhas:" << cont << endl;

    return 0;
}
