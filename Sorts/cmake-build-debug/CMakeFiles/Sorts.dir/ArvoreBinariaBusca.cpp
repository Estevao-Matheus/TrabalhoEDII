//
// Created by 1513 X-MXTI on 02/05/2019.
//

#include "ArvoreBinariaBusca.h"

ArvoreBinariaBusca::ArvoreBinariaBusca()
{
    altura = -1;
    raiz = nullptr;
}

int ArvoreBinariaBusca::getAltura()
{
    return altura;
}

void ArvoreBinariaBusca::insereNo(NoAVL *node)
{
    bool flag = true;
    NoAVL *aux, *aux2;
    aux = raiz;
    if(raiz == nullptr)
    {
        raiz = node;
        altura++;
    }
    else if(node->getChave() > aux->getChave())
    {
        if(aux->getDir() == nullptr)
        {
            aux->setDir(node);
            altura++;
        }
        else
        {
            //CHAMAR A FUNCAO DE NOVO PASSANDO COMO PARAMETRO O get
            altura++;
        }
    }
    else
    {
        if(aux->getEsq() == nullptr)
        {
            aux->setEsq(node);
        }
        else
        {
            //CHAMAR A FUNCAO DE NOVO
        }
    }

}