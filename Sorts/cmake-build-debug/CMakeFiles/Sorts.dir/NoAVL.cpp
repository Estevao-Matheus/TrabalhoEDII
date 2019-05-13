//
// Created by 1513 X-MXTI on 02/05/2019.
//

#include "NoAVL.h"

using namespace std;

NoAVL::NoAVL()
{
    chave = 0;
    esq = nullptr;
    dir = nullptr;
}

void NoAVL::setDir(NoAVL *no)
{
    dir = no;
}

void NoAVL::setEsq(NoAVL *no)
{
    esq = no;
}

NoAVL* NoAVL::getDir()
{
    return dir;
}

NoAVL* NoAVL::getEsq()
{
    return esq;
}

int NoAVL::getChave()
{
    return chave;
}

NoAVL::~NoAVL()
{

}
