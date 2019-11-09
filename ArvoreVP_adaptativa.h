#ifndef ARVOREVP_ADAPTATIVA_H
#define ARVOREVP_ADAPTATIVA_H

#include"Objeto.h"
#include"Usuario.h"

typedef struct novp_adaptado
{
    Usuario dado;
    int indice;
    struct novp_adaptado *esq,*dir,*pai;
    char cor;  ///'p'= preto 'v'= vermelho

} NoVP_adp;

class ArvoreVP_adaptativa
{
public:
    ArvoreVP_adaptativa();
    virtual ~ArvoreVP_adaptativa();

    int insereVP(Objeto chave, int indice);
//    void removeVP(int chave);
    int  buscaVP(int chave);
    void imprimeVP();
    void liberaNoVP(NoVP_adp *no);
    int height(NoVP_adp* root);
    NoVP_adp *raiz;


protected:

private:
//    NoVP *raiz;
    NoVP_adp *nulo;

    void rotacaoEsq(NoVP_adp* no);
    void rotacaoDir(NoVP_adp* no);

    void balanceamentoInsercao(NoVP_adp* no);
//    void insere_arvBinaria(NoVP* no, NoVP* novoNo, NoVP* pai, Objeto chave);
    void insere_arvBinaria(NoVP_adp* no, NoVP_adp* novoNo, NoVP_adp* pai, int *indice);
    void auxDestrutor(NoVP_adp* no);
    void auxImprime(NoVP_adp* no);
    void Vizualiza_ArvoreRedBlack( NoVP_adp* root);
    void printGivenLevel( NoVP_adp* root,int level, int h);
};

#endif // ARVOREVP_ADAPTATIVA_H
