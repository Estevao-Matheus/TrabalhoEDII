//
// Created by 1513 X-MXTI on 06/07/2019.
//

#ifndef HUFFMAN_NOHEAPMIN_H
#define HUFFMAN_NOHEAPMIN_H


class NoHeapMin {

public :char info;
public: int  frenquencia;
   NoHeapMin *esqu,*dir;

    public:
        NoHeapMin(char info,int frenquencia);
        bool vericaFolha();

    friend class HeapMin;
};


#endif //HUFFMAN_NOHEAPMIN_H
