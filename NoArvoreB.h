//
// Created by 1513 X-MXTI on 27/06/2019.
//

#ifndef ARVEROB_NOARVOREB_H
#define ARVEROB_NOARVOREB_H

#include "Usuario.h"


class NoArvoreB {

    Usuario *chaves;  // Array de chaves
    int t;      // ordem
    NoArvoreB **C; // ponteiros dos filhos
    int n;     // Numero atual de chaves
    bool folha; // bolleano que checa se o nó é ou não folha


    public:
            NoArvoreB(int graun, bool folhan);
            void atravessa();
            NoArvoreB *busca(int k,unsigned long long int *comp,unsigned long long int *cop);
            void insereNoCheio(Usuario k,unsigned long long int *comp,unsigned long long int *cop);
            void divideFilho(int i, NoArvoreB *y,unsigned long long int *comp,unsigned long long int *cop);

    friend class ArvoreB;
};



#endif //ARVEROB_NOARVOREB_H
