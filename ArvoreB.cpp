//
// Created by 1513 X-MXTI on 27/06/2019.
//
#include "ArvoreB.h"
 ArvoreB::ArvoreB(int _t)
{
  raiz = nullptr ;
  t = _t;
}

int ArvoreB::getOrdem()
{
    return t;
}

void ArvoreB::zeraConts()
{
    contcop = 0;
    contcomp = 0;
}
void ArvoreB::insere(Usuario k)
{
     if(raiz== nullptr) //se a arvore estiver vazia cria novo nó como raiz
         {
            raiz = new NoArvoreB(t,true);
            raiz->chaves[0]=k;
            raiz->n =1; // atualiza numero de chaves da raiz
            this->contcomp++;


         }else
             {
                if(raiz->n == 2*t-1) //se a raiz esta cheia cresce o tamanho
                {
                    NoArvoreB *s = new NoArvoreB(t,false); // aloca novo no
                    s->C[0]= raiz; //faz o novo nó de raiz
                    s->divideFilho(0,raiz,&this->contcomp,&this->contcop); //divide o nó antigo
                    this->contcomp++;
                    int i=0;
                    this->contcomp++;
                    if(s->chaves[0].userid<k.userid)
                    {
                        i++;

                    }
                    s->C[i]->insereNoCheio(k,&this->contcomp,&this->contcop);

                    raiz = s;
                }else
                {
                    raiz->insereNoCheio(k,&this->contcomp,&this->contcop);
                }



             }


}
void ArvoreB::atrvessa()
{

    if (raiz != nullptr) raiz->atravessa();
}

NoArvoreB* ArvoreB::busca(int k)
{
    return (raiz == nullptr)? nullptr : raiz->busca(k,&this->contcomp,&this->contcop);
}
