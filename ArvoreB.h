//
// Created by 1513 X-MXTI on 27/06/2019.
//

#ifndef ARVEROB_ARVOREB_H
#define ARVEROB_ARVOREB_H


#include "NoArvoreB.h"

class ArvoreB {

                NoArvoreB *raiz;
                int t; //ordem

          public:
                    ArvoreB(int _t);
                    void atrvessa();
                    NoArvoreB* busca(int k);
                    void insere(Usuario k);
                    unsigned long long int contcomp;
                    unsigned long long int contcop;
                    void zeraConts(); //zerar contadores
                    int getOrdem();



};




#endif //ARVEROB_ARVOREB_H
