//
// Created by 1513 X-MXTI on 06/07/2019.
//

#ifndef HUFFMAN_HEAPMIN_H
#define HUFFMAN_HEAPMIN_H


#include "NoHeapMin.h"

class HeapMin {

public :int tamanho;
    int capacidade;
    NoHeapMin **array;
    public:
        HeapMin(int capacidade);
        ~HeapMin();
        void Swap(NoHeapMin **a,NoHeapMin **b);
        void minHeapfy(int indice);
        NoHeapMin *extraimenor();
        void insereNo(NoHeapMin *no);
        void balanceiaHeapMin();
        void criaHepmin(char info[],int freq[],int tamanho);

};


#endif //HUFFMAN_HEAPMIN_H
