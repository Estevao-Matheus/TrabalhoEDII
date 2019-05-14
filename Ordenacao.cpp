#include "Objeto.h"
#include "Ordenacao.h"

int trocac,comparac;

void Ordenacao::troca(int *xp, int *yp)
{
    int aux = *xp;
    *xp = *yp;
    *yp = aux;

}

void Ordenacao::BubbleSort(Objeto *vet, int tamVet)
{

    auto start = chrono::steady_clock::now();
    int i,j;
    int trocacount = 0;
    int comparacount =0;
    for(i=0;i<tamVet-1;i++)
    {
        for(j=0;j<tamVet-i-1;j++)
        {
            comparacount++;
            if(vet[j].getUserID()>vet[j+1].getUserID())
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


void Ordenação::selectionsort (Objeto *vet,int tamVet)
{
    auto start = chrono::steady_clock::now();
    int i,j;
    int indicemin;
    int trocacount =0;
    int comparacount =0;
    for(i=0;i<tamVet-1;i++)
    {
        indicemin = i;
        for(j=i+1;j<tamVet;j++)
        {
            comparacount++;
            if(vet[j].getUserID()<vet[indicemin].getUserID())
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



void Ordenacao::InserctionSort (Objeto *vet,int tamVet)
{
    int trocacount=0;
    int comparacount=0;
    auto start = chrono::steady_clock::now();
    int i, j;
    Objeto chave(0, 0, 0, 0);;
    for (i = 1; i < tamVet; i++) {
        chave = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j].getUserID() > chave.getUserID()) {
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


void Ordenacao::ShellSort(Objeto *vet, int tamVet)
{
        auto start = chrono::steady_clock::now();
        int i, j;
        Objeto chave;
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




void Ordenacao::QuickSort(Objeto *vet, int tamVet) {
    trocac =0;
    comparac =0;
    auto start = chrono::steady_clock::now();
    AuxQuickSort(vet, 0, tamVet-1)
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"vetor ordenado em: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout<<"Comparações: "<<comparac<<endl;
    cout<<"Troacs: "<<trocac<<endl;
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
            trocac++;
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
    trocac =0;
    comparac =0;
    auto start = chrono::steady_clock::now();
    AuxQuickSortMediana(vet, 0, tamVet-1);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"vetor ordenado em: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout<<"Comparações: "<<comparac<<endl;
    cout<<"Troacs: "<<trocac<<endl;
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


void Ordenacao::MergeSort(Objeto *vet, int Esq, int Dir)
{

    trocac=0;
    comparac=0;
    auto start = chrono::steady_clock::now();
    mergeAux(vet,Esq,Dir);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"vetor ordenado em: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout<<"Comparações: "<<comparac<<endl;
    cout<<"Troacas: "<<trocac<<endl;




}



void Ordenacao::AuxMergeSort(Objeto *vet, int Esq, int Dir)
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



void Ordenacao::Intercala(Objeto *vet, int Esq, int media, int dir)
{
    int i, j, k;
    int n1 = media - Esq + 1;
    int n2 =  dir - media;

    // cria arrays temorárias
    Objeto ESQ[n1], DIR[n2];

    // copia dados pras arrays temporarias ESQ[] e DIR[]
    for (i = 0; i < n1; i++)
        ESQ[i] = vet[Esq + i];
    for (j = 0; j < n2; j++)
        DIR[j] = vet[media + 1+ j];

    // Merge the temp arrays back into vet[Esq..dir]
    i = 0; // indice inicial da primeira subarray
    j = 0; // indice inicial da segunda subarray
    k = Esq; // indice inicial da subarray fundida
    while (i < n1 && j < n2)
    {
        comparac++;
        if (ESQ[i].getUserID() <= DIR[j].getUserID())
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

    // Copia os elementos restantes de  ESQ[],se existir algum
    while (i < n1)
    {
        vet[k] = ESQ[i];
        i++;
        k++;
        trocac++;
    }

    // Copia os elementos de  DIR[], se tiver algum
    while (j < n2)
    {
        vet[k] = DIR[j];
        j++;
        k++;
        trocac++;
    }
}


//------------------------------------------QuickInsertionSort-----------------------------------------------------



void  Ordenacao::insertionSortAux (Objeto * vet, int low, int high)
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



void Ordenacao::quickInsertionAux(Objeto* vet, int low, int high) //high eh o INDICE FINAL, nao o TAMANHO
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


void Ordenacao::quickInsertion(Objeto* vet, int low, int high)
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