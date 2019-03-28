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
    getline(arq, strAux, '\n');//TRATAR A EXCEÇAO DE CASO O CURSOR PARE NA ULTIMA LINHA
    int cont = 0;
    if(arq.is_open())
    {
        string str;
        int* vetor = new int[qtdLinha];
        while(cont < qtdLinha)
        {
            if(!arq.eof()){//PROVISÓRIO, TEMOS QUE VERIFICAR SE FUNCIONA MESMO
                cont++;
                cout << "teste: " << cont << endl;
                getline(arq, str);
                vetor[cont-1] = parse(str);
                //cout << endl;
            }
        }
        insertionSort(vetor, cont);
    else
    {
        cout << "Erro, arquivo nao pode ser aberto" << endl;
    }
    arq.close();
    cout << "Numero de linhas:" << cont << endl;
}

int main()
{

    int vet[10] = {12, 8, 15, 1, 22, 9, 6, 14, 9, 10};
    selectionSort(vet, 10);
    for(int k = 0; k < 10; k++)
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
