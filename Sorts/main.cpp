#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;

int trocac,comparac;

void imprimearray (int vet[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        cout<< vet[i]<<" ";
    }
}

void troca(int *xp, int *yp)
{
    int aux = *xp;
    *xp = *yp;
    *yp = aux;
}



int bubblesort (int *vet, int tam)
{
    auto start = chrono::steady_clock::now();
    int i,j;
    int trocacount = 0;
    int comparacount =0;
    for(i=0;i<tam-1;i++)
    {
        for(j=0;j<tam-i-1;j++)
        {
            comparacount++;
            if(vet[j]>vet[j+1])
            {
                troca(&vet[j],&vet[j+1]);
                trocacount++;

            }
        }
        if(trocacount==0)
            break;
    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"vetor ordenado em: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout<<"Numero de comparações;"<<comparacount<<endl;
    cout<<"Numero de trocas;"<<trocacount<<endl;
}

int selectionsort (int *vet,int tam)
{
    auto start = chrono::steady_clock::now();
    int i,j;
    int indicemin;
    int trocacount =0;
    int comparacount =0;
    for(i=0;i<tam-1;i++)
    {
        indicemin = i;
        for(j=i+1;j<tam;j++)
        {
            comparacount++;
            if(vet[j]<vet[indicemin])
            {
                indicemin = j;
            }
        }
        troca(&vet[indicemin],&vet[i]);
        trocacount++;
    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"vetor ordenado em: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout<<"Numero de comparações;"<<comparacount<<endl;
    cout<<"Numero de trocas;"<<trocacount<<endl;

}

int inserctionsort (int  *vet,int tam)
{
    int trocacount=0;
    int comparacount=0;
    auto start = chrono::steady_clock::now();
    int i,chave, j;
    for (i = 1; i < tam; i++) {
        chave = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            j = j - 1;
            comparacount++;
        }
        vet[j + 1] = chave;
        trocacount++;
    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"vetor ordenado em: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout<<"Numero de comparações;"<<comparacount<<endl;
    cout<<"Numero de trocas;"<<trocacount<<endl;
}

void merge(int vet[], int Esq, int media, int dir)
{
    int i, j, k;
    int n1 = media - Esq + 1;
    int n2 =  dir - media;

    /* cria arrays temorárias */
    int ESQ[n1], DIR[n2];

    /* copia dados pras arrays temporarias ESQ[] e DIR[] */
    for (i = 0; i < n1; i++)
        ESQ[i] = vet[Esq + i];
    for (j = 0; j < n2; j++)
        DIR[j] = vet[media + 1+ j];

    /* Merge the temp arrays back into vet[Esq..dir]*/
    i = 0; // indice inicial da primeira subarray
    j = 0; // indice inicial da segunda subarray
    k = Esq; // indice inicial da subarray fundida
    while (i < n1 && j < n2)
    {
        comparac++;
        if (ESQ[i] <= DIR[j])
        {
            vet[k] = ESQ[i];
            i++;
            trocac++;
        }
        else
        {
            vet[k] = DIR[j];
            j++;
            trocac++;
        }
        k++;
    }

    /* Copia os elementos restantes de  ESQ[],
     * se existir algum */
    while (i < n1)
    {
        vet[k] = ESQ[i];
        i++;
        k++;
        trocac++;
    }

    /* Copia os elementos de  DIR[], se tiver algum */
    while (j < n2)
    {
        vet[k] = DIR[j];
        j++;
        k++;
        trocac++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeAux(int vet[], int Esq, int Dir)
{
    if (Esq < Dir)
    {

        int media = Esq+(Dir-Esq)/2;

        // Sort primeira e segunda metade
        mergeAux(vet, Esq, media);
        mergeAux(vet, media+1, Dir);
        merge(vet, Esq, media, Dir);
    }
}

void mergeSort(int vet[], int Esq, int Dir)
{

    auto start = chrono::steady_clock::now();
    mergeAux(vet,Esq,Dir);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"vetor ordenado em: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout<<"Comparações: "<<comparac<<endl;
    cout<<"Troacas: "<<trocac<<endl;




}


/*
    Essa funcao pega o ultimo elemento como pivô, coloca o pivô na sua posição correta
    no vetor ordenado, e coloca todos os menores que o pivô à esquerda do pivô e todos os maiores à direita.
*/
int particiona (int vet[], int low, int high)
{
    // pivot (Elemento a ser colocado na posição certa)
    int pivot = vet[high];

    int i = (low - 1);  // Indice do menor elemento

    for (int j = low; j <= (high - 1); j++)
    {
        // Se o elemento atual é menor ou
        // igual ao pivot
        if (vet[j] <= pivot)
        {
            i++;    // incrementa indice do elemento menor
            comparac++;
            troca(&vet[i],&vet[j]);
            trocac++;


        }
    }
    troca(&vet[i+1],&vet[high]);
     trocac++;


    return (i + 1);
}

/* low  --> indice do começo,  high  --> indice do fim */
void quickAux(int vet[], int low, int high)
{

    if (low < high)
    {
        /* pi é o índice de particionamento, vet[pi] está agora no lugar certo */
        int pi = particiona(vet, low, high);

        quickAux(vet, low, pi - 1);  // Antes do pi
        quickAux(vet, pi + 1, high); // Depois do pi
    }

}

void quickSort(int vet[],int low,int high)
{
    trocac =0;
    comparac =0;
    auto start = chrono::steady_clock::now();
    quickAux(vet,low,high);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"vetor ordenado em: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout<<"Comparações: "<<comparac<<endl;
    cout<<"Troacs: "<<trocac<<endl;


}

//------------------------------------------QuickInsertionSort-----------------------------------------------------



void  insertionSort (int * vet, int low, int high)
{
    int pivo =low;
    int j = low;

    for (int i = (low+1); i <=high; i ++)
    {
        pivo = vet [i];
        j = i- 1 ;
        while (j>= low && vet[j]  > pivo)
        {
            vet [j + 1 ] = vet [j];
            j--;
        }
        vet [j + 1 ] = pivo;
    }
}



void quickInsertionAux(int* vet, int low, int high) //high eh o INDICE FINAL, nao o TAMANHO
{
    if (((high+1)-low)>10)//verificando se o tamanho do vetor eh maior que 10
    {
        // pi é o índice de particionamento, vet[pi] está agora no lugar certo
        int pi = particiona(vet, low, high);

        quickInsertionAux(vet, low, pi - 1);  // Antes do pi
        quickInsertionAux(vet, pi + 1, high); // Depois do pi
    }
    else   //se o vetor for menor que 10 elementos, usamos o insertionSort
    {
        insertionSort(vet, low, high);
    }
}


void quickInsertion(int* vet, int low, int high)
{
    trocac = 0;
    comparac =0;
    auto start = chrono::steady_clock::now();
    quickInsertionAux(vet,low,high);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"vetor ordenado em: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout<<"Comparações: "<<comparac<<endl;
    cout<<"Troacs: "<<trocac<<endl;

}



void shellSort(int *vet, int tamVet)
{
    auto start = chrono::steady_clock::now();
    int i, j, chave;
    int comparacount=0;
    int trocacount =0;
    int gap = 1;
    while(gap < tamVet)  //Calculando o gap inicial(gap eh a distancia de um indice a outro)
    {
        gap = 3*gap+1;
    }
    while ( gap > 1)
    {
        gap /= 3;//Atualizando gap, ate ele valer 1
        for(i = gap; i < tamVet; i++)//Compara o elemento do indice 'j' com o elemento do indice "j+gap" em todo vetor
        {
            comparacount++;
            chave = vet[i];
            j = i - gap;
            while (j >= 0 && chave < vet[j])//verifica se eh necessario a troca
            {
                vet [j + gap] = vet[j];
                j -= gap;
                trocacount++;
            }
            vet [j + gap] = chave;
        }
    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"vetor ordenado em: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout<<"Numero de comparações;"<<comparacount<<endl;
    cout<<"Numero de trocas;"<<comparacount<<endl;
}

int main()
{
    int *vet;
    int tam;
    cout<<"Qual o tamanho do vetor a ser ordenado"<<endl;
    cin>>tam;
    vet = new int [tam];
    srand (time(NULL));
    for(int i=0;i<tam;i++)
    {
        vet[i]= rand() % 1000;
    }
    quickInsertion(vet,0,tam);
    imprimearray(vet,tam);






}

