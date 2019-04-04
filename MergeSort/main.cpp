#include <iostream>
#include <stdio.h>

using namespace std;

void intercala(int inicio_vet,int inicio_vet2,int fim_vet,int vet[])
{
    int indice_ini,indice_ini_vet_2,indice_aux;
    int *vet_aux;
    vet_aux = new int [fim_vet * sizeof(int)];
    indice_ini = inicio_vet;
    indice_ini_vet_2 = inicio_vet2;
    indice_aux=0;
    while(indice_ini<inicio_vet2&&indice_ini_vet_2<fim_vet)
    {
        cout<<"Teste"<<endl;
        if(vet[indice_ini]<=vet[indice_ini_vet_2])
        {
            vet_aux[indice_aux]=vet[indice_ini];
            indice_aux++;
            indice_ini++;
            cout<<"Testeif"<<endl;
        }else
        {
            vet_aux[indice_aux] = vet[indice_ini_vet_2];
            indice_aux++;
            indice_ini_vet_2++;
            cout<<"Testeelse"<<endl;
        }
    }
    while(indice_ini<inicio_vet2)
    {
        cout<<"Testewhile2"<<endl;
        vet_aux[indice_aux]=vet[indice_ini];
        indice_aux++;
        indice_ini++;
    }
    while(indice_ini_vet_2<fim_vet)
    {
        vet_aux[indice_aux] = vet[indice_ini_vet_2];
        indice_aux++;
        indice_ini_vet_2++;
        cout<<"TesteWhile3"<<endl;
    }
    for(indice_ini=inicio_vet;indice_ini<fim_vet;indice_ini++)
    {
        vet[indice_ini] = vet_aux[indice_ini-inicio_vet];
        cout<<"TesteFor"<<endl;
    }
    delete vet_aux;

}


int mergesort (int*vetor, int inicio, int fim)
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

int main() {
    int vetorTeste[] = {12, 44, 32, 76, 78, 1, 4, 16, 9, 53};
    mergesort(vetorTeste, 0, 10);
    for(int i = 0; i<10; i++) {
        cout << vetorTeste[i] << ", ";
    }
    return 0;
}