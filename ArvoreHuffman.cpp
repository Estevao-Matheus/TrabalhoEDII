
//

#include "ArvoreHuffman.h"
#include "iostream"

using namespace std;

ArvoreHuffman::ArvoreHuffman(int capacidade)
{
    arvoreHuff = new HeapMin(capacidade);

}

ArvoreHuffman::~ArvoreHuffman()
{
    delete arvoreHuff;

}

void ArvoreHuffman::constroiHuffman(char *info, int *freq, int tamanho)
{
    // adiciona os elementos na heapmin onde sera construida a arvore Huffman
    arvoreHuff->criaHepmin(info,freq,tamanho);

    while (arvoreHuff->tamanho!=1)
    {


//junta os de menor frequencia
        esquerda = arvoreHuff->extraimenor();
        direita = arvoreHuff->extraimenor();



        topo = new NoHeapMin('$',esquerda->frenquencia+direita->frenquencia); //cria nó de ligação


        topo->esqu = esquerda;
        topo->dir = direita;

        arvoreHuff->insereNo(topo);
    }

    raiz=arvoreHuff->extraimenor();




}

void ArvoreHuffman::CodigoHuffman(string *codigo)
{

    int top =0;
    int array[100];              // gera o vetor que vai armazenar o codico
    codigoHuffmanaux(raiz,array,top,codigo);

}

void ArvoreHuffman::codigoHuffmanaux(NoHeapMin *raiz, int *array, int top, string*codigo)
{

    // percorre a arvore até a folha armazeando 0 ou 1 de acordo com o caminho tomado gerando assim o codigo do caracter
    if (raiz->esqu)
    {

        array[top] = 0;
        codigoHuffmanaux(raiz->esqu, array, top + 1, codigo);
    }


    if (raiz->dir)
    {

        array[top] = 1;
        codigoHuffmanaux(raiz->dir, array, top + 1, codigo);
    }


    if (raiz->vericaFolha())
    {
        int idx= 0;
        idx = (int)raiz->info;
        if(!(idx>255||idx<0))
            imprimearray(array, top, codigo, idx);
    }


}

void ArvoreHuffman::imprimearray(int *arr, int n, string* codigo, int idx)
{
    // passa o codigo gerado pro vetor de codigos
    int j =0;
    for(j=0; j<n; j++)
    {

        if(arr[j]==0)
            codigo[idx][j] = '0';
        else if(arr[j]==1)
            codigo[idx][j] = '1';

    }

    codigo[idx][j] = '\0';
}
