//
// Created by 1513 X-MXTI on 27/06/2019.
//

#include "NoArvoreB.h"
#include "iostream"

using namespace std;
NoArvoreB::NoArvoreB(int graun, bool folhan)
{

    t = graun;
    folha = folhan;
    chaves = new Usuario[2*t-1]; // calcula e aloca memoria para a quantidade maxima de chaves contidas no nó
    C = new NoArvoreB *[2*t]; // calula quantidade de ponteiros filhos


    n = 0; //inicializa numero atual de chaves em 0
}

void NoArvoreB::atravessa() {

// funçao que percorre toda a subarvore ligada a esse nó (n chaves e n+1 filhos)
    int i;
    for (i = 0; i < n; i++)
    {
        // verifica se é folha se não for continua travessia
        if (folha == false) {
            C[i]->atravessa();
        }
        cout << " " << chaves[i].userid;
        //imprime o nó atual
    }
    //imprime subarvore atual
    if (folha == false)
        C[i]->atravessa();
}

NoArvoreB* NoArvoreB::busca(int k,unsigned long long int*comp,unsigned long long int*cop)
{
    int i = 0;
    //acha a primeira chave maior ou igual a k
    while (i < n && k > chaves[i].userid) {
        i++;
        (*comp)++;
    }
    (*comp)+=2;
        //se for igual retorna a chave
        if (chaves[i].userid == k)
        {
            return this;
        }
        (*comp)++;
        //se não encontrar e nó for folha retorna nulo
        if (folha == true)
        {
            return nullptr;
        }
        //chama recursivamente pra continuar a busca
        return C[i]->busca(k,comp,cop);



}

void NoArvoreB::insereNoCheio(Usuario k,unsigned long long int *comp,unsigned long long int*cop) {
    int i = n - 1;
    (*comp)++;
    //se o no for folha
    if (folha == true) {
            //acha a localização da nova chave
        while (i >= 0 && chaves[i].userid > k.userid) {
            (*comp)+=2;
            chaves[i + 1] = chaves[i];
    //move as chaves maiores para a nova chave ser inserida
            i--;
        }

        chaves[i + 1] = k; // insere a nova chave
        n = n + 1;


    } else {
        //se não for folha ache o filho onde será inserido
        while (i >= 0 && chaves[i].userid > k.userid) {
            (*comp)+=2;
            i--;
        }
        (*comp)++;
        //ve se o filho esta cheio
        if (C[i + 1]->n == 2 * t - 1) {
            divideFilho(i + 1, C[i + 1],comp,cop);
            //se tiver divide
            (*comp)++;
            // depois insere a chave
            if (chaves[i + 1].userid < k.userid) {
                i++;
            }
        }
        C[i + 1]->insereNoCheio(k,comp,cop);

    }

}



void NoArvoreB::divideFilho(int i, NoArvoreB *y,unsigned long long int *comp,unsigned long long int *cop) {

    NoArvoreB *z = new NoArvoreB(y->t, y->folha); //cria novo nó que vai armazenar t-1 chaves
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++) {
        (*comp)++;
        z->chaves[j] = y->chaves[j + t]; // cppia t-1 chaves de y para z
    }
    (*comp)++;
    if (y->folha == false) {
        for (int j = 0; j < t; j++)
        {
            (*comp)++;
            z->C[j] = y->C[j + t];
        }
    }
    y->n = t - 1; // reduz o numero de chaves em y
    for (int j = n; j >= i + 1; j--) {
        C[j + 1] = C[j];
        (*comp)++;

    }
    C[i + 1] = z; // cria espaço pro novo filho
    for (int j = n - 1; j >= i; j--) {
        (*comp)++;
        chaves[j + 1] = chaves[j];
    }
    chaves[i] = y->chaves[t - 1];
    n=n+1; // incrementa o contador de chaves desse nó
}






