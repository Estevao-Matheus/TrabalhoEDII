#ifndef ARVOREVP_H
#define ARVOREVP_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "string.h"


#include "Usuario.h"

using namespace std;


typedef struct novp
{
    Usuario dado;
    struct novp *esq,*dir,*pai;
    char cor;  ///'p'= preto 'v'= vermelho

} NoVP;


class ArvoreVP
{
public:
    ArvoreVP();
    virtual ~ArvoreVP();
    void insereVP(Usuario chave);
//    void removeVP(int chave);
    NoVP*  buscaVP(int chave);
    void imprimeVP();
    void liberaNoVP(NoVP *no);
    int height(NoVP* root);
    unsigned long long int comparacoes, copias;
    NoVP *raiz;
    void zeraConts();


protected:

private:
//    NoVP *raiz;
    NoVP *nulo;

    void rotacaoEsq(NoVP* no);
    void rotacaoDir(NoVP* no);

    void balanceamentoInsercao(NoVP* no);
    void insere_arvBinaria(NoVP* no, NoVP* novoNo, NoVP* pai, Usuario chave);
    void auxDestrutor(NoVP* no);
    void auxImprime(NoVP* no);
    void Vizualiza_ArvoreRedBlack( NoVP* root);
    void printGivenLevel( NoVP* root,int level, int h);
};



#endif // ARVOREVP_H
