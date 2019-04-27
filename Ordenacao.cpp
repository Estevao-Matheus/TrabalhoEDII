#include "Objeto.h"
#include "Ordenacao.h"

Ordenacao::Ordenacao() { }

Ordenacao::~Ordenacao() { }

void Ordenacao::BubbleSort(Objeto *vet, int tamVet)
{
    bool troca = true;
    for(int i =0; i <tamVet-1 && troca; i++){
        troca = false;
        for(int j = 0; j<tamVet-1-i; j++){
            if(vet[j].getUserID()>vet[j+1].getUserID()){
                Objeto aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                troca = true;
            }
        }
    }
}

void Ordenacao::SelectionSort(Objeto *vet, int tamVet)
{
    int menor = 0;
    for(int i =0; i <tamVet-1; i++){
        menor = i;
        for(int j = i+1; j<tamVet; j++){
            if(vet[menor].getUserID() > vet[j].getUserID()){
                menor = j;
            }
        }
        Objeto aux = vet[menor];
        vet[menor] = vet[i];
        vet[i] = aux;
    }
}

void Ordenacao::InsertionSort(Objeto *vet, int tamVet)
{
    Objeto pivo(0, 0, 0, 0);
    int j = 0;
    for(int i = 1; i < tamVet; i ++){
        pivo = vet[i];
        j = i-1;
        while(j >= 0 && vet[j].getUserID() > pivo.getUserID()){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = pivo;
    }
}

void Ordenacao::QuickSort(Objeto *vet, int tamVet) {

}



void Ordenacao::intercala(int inicio_vet,int inicio_vet2,int fim_vet,int vet[])
{
    int indice_ini,indice_ini_vet_2,indice_aux;
    int *vet_aux;
    vet_aux = new int [fim_vet * sizeof(int)];
    indice_ini = inicio_vet;
    indice_ini_vet_2 = inicio_vet2;
    indice_aux=0;
    while(indice_ini<inicio_vet2&&indice_ini_vet_2<fim_vet)
    {
        if(vet[indice_ini]<=vet[indice_ini_vet_2])
        {
            vet_aux[indice_aux]=vet[indice_ini];
            indice_aux++;
            indice_ini++;
        }else
        {
            vet_aux[indice_aux] = vet[indice_ini_vet_2];
            indice_aux++;
            indice_ini_vet_2++;
        }
    }
    while(indice_ini<inicio_vet2)
    {
        vet_aux[indice_aux]=vet[indice_ini];
        indice_aux++;
        indice_ini++;
    }
    while(indice_ini_vet_2<fim_vet)
    {
        vet_aux[indice_aux] = vet[indice_ini_vet_2];
        indice_aux++;
        indice_ini_vet_2++;
    }
    for(indice_ini=inicio_vet;indice_ini<fim_vet;indice_ini++)
    {
        vet[indice_ini] = vet_aux[indice_ini-inicio_vet];
    }
    delete vet_aux;

}


int Ordenacao::mergesort(int*vetor, int inicio, int fim)
{
    int meio;
    if(inicio<fim)
    {
        meio = (inicio+fim)/2;
        mergesort(vetor,inicio,meio);
        mergesort(vetor,meio+1,fim);
        intercala(inicio,meio,fim,vetor);
    }
}
