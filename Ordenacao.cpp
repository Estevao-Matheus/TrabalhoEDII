#include "Objeto.h"
#include "Ordenacao.h"

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

void Ordenacao::ShellSort(Objeto *vet, int tamVet)
{
    int i, j, gap = 1;
    Objeto auxiliar;
    while(gap < tamVet) {
        gap = 3*gap + 1;
    }

    while(gap > 1)
    {
        gap /= 3;
        for(i = gap; i < tamVet; i++)
        {
            auxiliar = vet[i];
            j = i - gap;
            while(j >= 0 && auxiliar.getUserID() < vet[j].getUserID())
            {
                vet[j + gap] = vet[j];
                j -= gap;
            }
            vet[j + gap] = auxiliar;
        }
    }
}


void Ordenacao::QuickSort(Objeto *vet, int tamVet) {
    AuxQuickSort(vet, 0, tamVet-1);
}

void Ordenacao::AuxQuickSort(Objeto *vet, int inicio, int fim)
{
    if(inicio < fim)
    {
        // pi é o índice de particionamento
        int pi = Particiona(vet, inicio, fim, vet[fim].getUserID());

        AuxQuickSort(vet, inicio, pi - 1); // Antes do pi
        AuxQuickSort(vet, pi, fim); // Depois do pi
    }
}

int Ordenacao::Particiona(Objeto *vet, int inicio, int fim, int pivot)
{
    int leftPtr = inicio - 1;
    int rightPtr = fim + 1;
    while(true)
    {
        while((leftPtr < fim) && (vet[++leftPtr].getUserID() < pivot))
        { }
        while((rightPtr > inicio) && (vet[--rightPtr].getUserID() > pivot))
        { }
        if(leftPtr >= rightPtr)
            break;
        else
            Troca(vet, leftPtr, rightPtr);
    }
    return leftPtr;
}

void Ordenacao::Troca(Objeto *vet, int i, int j)
{
    Objeto  aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

void Ordenacao::QuickSortMediana(Objeto* vet, int tamVet)
{
    AuxQuickSortMediana(vet, 0, tamVet-1);
}


void Ordenacao::AuxQuickSortMediana(Objeto *vet, int inicio, int fim)
{
    int tamanho = fim - inicio + 1;
    if(tamanho <= 3)
        AuxQuickSort(vet, inicio, fim);
    else
    {
        int media = MediaDe3(vet, inicio, fim);
        int particao = Particiona(vet, inicio, fim, media);
        AuxQuickSortMediana(vet, inicio, particao - 1);
        AuxQuickSortMediana(vet, particao, fim);
    }
}

int Ordenacao::MediaDe3(Objeto *vet, int inicio, int fim)
{
    int centro = (inicio + fim)/2;

    if(vet[inicio].getUserID() > vet[centro].getUserID())
        Troca(vet, inicio, centro);
    if(vet[inicio].getUserID() > vet[fim].getUserID())
        Troca(vet, inicio, fim);
    if(vet[centro].getUserID() > vet[fim].getUserID())
        Troca(vet, centro, fim);

    Troca(vet, centro, fim);
    return vet[fim].getUserID();
}

/* ---- ---- ---- ---- ---- ---- // ---- ---- ---- ----
int particiona !!antigo!! (Objeto *vet, int low, int high, int pivot)
{
    int i = (low - 1);  // Indice do menor elemento

    for (int j = low; j <= (high - 1); j++)
    {
        // Se o elemento atual é menor ou
        // igual ao pivot
        if (vet[j].getUserID() <= pivot)
        {                                                                           ___
            i++;    // incrementa indice do elemento menor                     ___ /   \
            troca(vet, i, j);                                      ____       /   \|   |
        }                                                        / o o \BoooOO\___/\___/
    }                                                           /  c=   /                  particiona antigo
    troca(vet, i+1, high);
    return (i + 1);
}
*/

void Ordenacao::MergeSort(Objeto *vetor, int tamVet)
{
    AuxMergeSort(vetor, 0, tamVet-1);
}

void Ordenacao::AuxMergeSort(Objeto *vet, int inicio, int fim)
{
    int meio;
    if(inicio < fim)
    {
        meio = (inicio + fim)/2;
        AuxMergeSort(vet, inicio, meio);
        AuxMergeSort(vet, meio + 1, fim);
        Intercala(vet, inicio, meio, fim);
    }
}

void Ordenacao::Intercala(Objeto *vet, int inicio, int meio, int fim)
{
    int indice_inicio, indice_inicio_vet_2, indice_aux;
    Objeto *vetor_aux;

    indice_aux = 0;
    indice_inicio = inicio;
    indice_inicio_vet_2 = meio + 1;
    vetor_aux = new Objeto[(fim - inicio + 1) * sizeof(int)];

    while(indice_inicio < meio + 1 && indice_inicio_vet_2 < fim + 1)
    {
        if(vet[indice_inicio].getUserID() <= vet[indice_inicio_vet_2].getUserID())
        {
            vetor_aux[indice_aux] = vet[indice_inicio];
            indice_aux++;
            indice_inicio++;
        }else
        {
            vetor_aux[indice_aux] = vet[indice_inicio_vet_2];
            indice_aux++;
            indice_inicio_vet_2++;
        }
    }

    while(indice_inicio < meio + 1)
    {
        vetor_aux[indice_aux] = vet[indice_inicio];
        indice_aux++;
        indice_inicio++;
    }
    while(indice_inicio_vet_2 < fim + 1)
    {
        vetor_aux[indice_aux] = vet[indice_inicio_vet_2];
        indice_aux++;
        indice_inicio_vet_2++;
    }

    for(indice_inicio = inicio; indice_inicio < fim + 1; indice_inicio++)
    {
        vet[indice_inicio] = vetor_aux[indice_inicio - inicio];
    }
    delete vetor_aux;
}