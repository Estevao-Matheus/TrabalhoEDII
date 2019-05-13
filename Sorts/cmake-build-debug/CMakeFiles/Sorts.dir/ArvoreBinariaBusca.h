//
// Created by 1513 X-MXTI on 02/05/2019.
//

#ifndef SORTS_ARVOREBINARIABUSCA_H
#define SORTS_ARVOREBINARIABUSCA_H

#include "NoAVL.h"

class ArvoreBinariaBusca {
public:
    ArvoreBinariaBusca();
    ~ArvoreBinariaBusca();
    void insereNo(NoAVL *node);
    void removeNo(int chave);
    NoAVL* buscaNo(int chave);
    int getAltura();

private:
    int altura;
    NoAVL* raiz;
};


#endif //SORTS_ARVOREBINARIABUSCA_H
