//
// Created by 1513 X-MXTI on 06/07/2019.
//

#include "HeapMin.h"
#include "iostream"
using namespace std;
HeapMin::HeapMin( int cap)
{
    capacidade=cap;
    tamanho=0;
    array = new NoHeapMin*[cap];


}

HeapMin::~HeapMin()
{
    cout<<endl<<"deletando heapfy"<<endl;
//    system("pause");
    for(int i=0;i<capacidade;i++)
    {
        delete array[i];
    }
    delete [] array;


}

void HeapMin::Swap(NoHeapMin **a, NoHeapMin **b) //Funçao que troca posiçoes entre doi nós
{
    NoHeapMin *temp =*a;
    *a=*b;
    *b=temp;


}

void HeapMin::minHeapfy(int indice)
{
   //função que rebalanceia a heap pra funcionar similar a uma arvore binaria
    int menor = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < tamanho && array[esquerda]->frenquencia <array[menor]->frenquencia) //verifica os casos pra tranformar em filho a direita ou esqerda
        menor = esquerda;

    if (direita < tamanho && array[direita]->frenquencia < array[menor]->frenquencia)
        menor = direita;

    if (menor != indice)
    {
//        cout<<"Aki ";
        Swap(&array[menor],&array[indice]);
        minHeapfy( menor);
    }
}


NoHeapMin *HeapMin::extraimenor()
{

 //busca menor valor dentro da heap
    NoHeapMin *temp = array[0];
    array[0]=array[tamanho-1];
    tamanho--;
    minHeapfy(0);
    return temp;

}
void HeapMin::insereNo(NoHeapMin *no)
{
    ++tamanho;
    int i = tamanho - 1;
    //vai a partir da metado por que a segunda metade são somente filhos
    while (i && no->frenquencia < array[(i - 1) / 2]->frenquencia) {
        array[i] = array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    array[i] = no;

}
void HeapMin::balanceiaHeapMin()
{
    //percorre toda a heap rodando a função minHeapfy pra balancear no total
    int n = tamanho - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapfy(i);


}
void HeapMin::criaHepmin(char info[], int freq[],int tamanho)
{


    for (int i = 0; i < tamanho; ++i){

        NoHeapMin *teste = new NoHeapMin(info[i], freq[i]);

        array[i] = teste;
    }


    this->tamanho = tamanho;

    balanceiaHeapMin();




}
