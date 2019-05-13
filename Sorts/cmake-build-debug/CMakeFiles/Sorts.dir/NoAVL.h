//
// Created by 1513 X-MXTI on 02/05/2019.
//

#ifndef SORTS_NOAVL_H
#define SORTS_NOAVL_H


class NoAVL {
public:
    NoAVL();
    ~NoAVL();
    NoAVL*  getDir();
    NoAVL*  getEsq();
    void setDir(NoAVL *no);
    void setEsq(NoAVL *no);
    int getChave();

private:
    NoAVL *esq;
    NoAVL *dir;
    int chave;


};


#endif //SORTS_NOAVL_H
