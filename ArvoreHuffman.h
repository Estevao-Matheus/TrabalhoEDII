//
// Created by 1513 X-MXTI on 06/07/2019.

#include "HeapMin.h"
#ifndef HUFFMAN_ARVOREHUFFMAN_H
#define HUFFMAN_ARVOREHUFFMAN_H


#include "NoHeapMin.h"
#include <string.h>
#include<string>
#include<iostream>
using namespace std;

class ArvoreHuffman {

    NoHeapMin *topo,*esquerda,*direita; //Heap e Nó que constituem a arvore Huffman
    HeapMin   *arvoreHuff;
    NoHeapMin *raiz;


    public:
            ArvoreHuffman(int capacidade);
            ~ArvoreHuffman();
            void constroiHuffman(char info[], int freq[], int tamanho);
            void CodigoHuffman(string *codigo);
            void codigoHuffmanaux(NoHeapMin *raiz,int array[],int top, string *codigo);
            void imprimearray(int arr[], int n, string *codigo, int idx);


};


#endif //HUFFMAN_ARVOREHUFFMAN_H
