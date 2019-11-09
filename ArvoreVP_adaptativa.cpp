#include "ArvoreVP_adaptativa.h"
#include "Usuario.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "string.h"
#include "Usuario.h"

using namespace std;

ArvoreVP_adaptativa::ArvoreVP_adaptativa()
{
   //DEFININDO NO' NULO E DEIXANDO ELE COM A COR PRETA
    nulo = new NoVP_adp;
    nulo->pai = nulo;
    nulo->esq = nulo;
    nulo->dir = nulo;
    nulo->cor = 'p';
    //INICIANDO A RAIZ COMO NULO
    raiz = nulo;
}

ArvoreVP_adaptativa::~ArvoreVP_adaptativa()
{
    cout<<"\n\n DELETANDO ARVORE VERMELHO PRETO...";
    auxDestrutor(raiz);
    delete nulo;
    cout<<"\n";
}



void ArvoreVP_adaptativa::auxDestrutor(NoVP_adp* no)
{
    if(no!=nulo&&no!=NULL)
    {
        NoVP_adp* aux1 = no->esq;
        NoVP_adp* aux2 = no->dir;
        delete no;
        auxDestrutor(aux1);
        auxDestrutor(aux2);
    }
}

void ArvoreVP_adaptativa::rotacaoEsq(NoVP_adp* no)
{
/// I)    VO
///         \
///          NO
///         /  \
///        A     AUX
///       / \   /   \
///      B   C  D    E
///


/// II)   VO
///         \
///          AUX
///         /   \
///       NO     E
///      / \
///     A   D
///    / \
///   B   C
///

    NoVP_adp * aux = no->dir;
    no->dir = aux->esq;

    if(aux->esq != nulo)
        aux->esq->pai = no;
    aux->pai = no->pai;

    if(no->pai == nulo)
        raiz = aux;
    else if(no == no->pai->esq)
        no->pai->esq = aux;
    else
        no->pai->dir = aux;

    aux->esq = no;
    no->pai = aux;

}

void ArvoreVP_adaptativa::rotacaoDir(NoVP_adp* no)
{
    NoVP_adp* aux = no->esq;
    no->esq = aux->dir;

    if(aux->dir != nulo)
        aux->dir->pai = no;
    aux->pai = no->pai;

    if(no->pai == nulo)
        raiz = aux;
    else if(no == no->pai->esq)
        no->pai->esq = aux;
    else
        no->pai->dir = aux;

    aux->dir = no;
    no->pai = aux;
}

int ArvoreVP_adaptativa::insereVP(Objeto chave, int indice)
{
    ///CRIANDO NOVO NO' PARA INSERIR NA ARVORE
    NoVP_adp* novoNo = new NoVP_adp;
    novoNo->cor = 'v';//O NO' SEMPRE EH INSERIDO COM A COR VERMELHA
    novoNo->dado.insere(chave.getUserID(),chave.getMovieID(),chave.getRating());
    int aux = indice;
    novoNo->indice = indice;
    novoNo->pai = nulo;
    novoNo->esq = nulo;
    novoNo->dir = nulo;

    if(raiz==nulo)///Se a arvore estiver vazia...
    {
        raiz = novoNo;//INSERE AKI
    }
    else
        insere_arvBinaria(raiz, novoNo, raiz->pai, &indice);///Se a arvore nao estiver vazia, vc insere igual na arvore binaria de busca
//    imprimeVP();
    ///DEPOIS DE INSERIRIR COMO NA ARVORE BINARIA DE BUSCA, EH PRECISO
    ///BALANCEAR A ARVORE, OBEDECENDO AS PROPRIEDADES DA ARVORE VERMELHO E PRETO
    balanceamentoInsercao(novoNo);
    if(aux==indice)
        return -1;
    return indice;
}

void ArvoreVP_adaptativa::insere_arvBinaria(NoVP_adp* no, NoVP_adp* novoNo, NoVP_adp* pai, int *indice)
{
    if(no==nulo)///CASO BASE, aki inserimos o no'
    {
        novoNo->pai = pai;

        if(novoNo->dado.userid <  pai->dado.userid   )///se no' eh menor que o pai...
        {
            pai->esq = novoNo;///entao o no' eh filho a esquerda
        }
        else if(novoNo->dado.userid > pai->dado.userid) ///se o no' eh maior que o pai
        {
            pai->dir = novoNo;///entao o no' eh filho a direita
        }
        else if(novoNo->dado.userid == pai->dado.userid)
        {
            std::vector<int>::iterator t;
            t=novoNo->dado.movieid.begin();
            int movieid = (*t);

            std::vector<float>::iterator t2;
            t2 = novoNo->dado.ratings.begin();
            float rating = (*t);

            pai->dado.insereFilme(movieid, rating);
            (*indice) = pai->indice;
        }
    }
    else
    {
        if(novoNo->dado.userid < no->dado.userid)///se o filho eh menor, insere a esquerda
        {
            insere_arvBinaria(no->esq, novoNo, no, indice);
        }

        else ///se o filho eh maior igual, insere a direita
        {
            insere_arvBinaria(no->dir, novoNo, no, indice);
        }
    }
}


//void ArvoreVP::balanceamentoInsercao(NoVP* no)
//{
//    while(no->pai->cor=='v')///Se o no-> pai for preto, ele nao desbalanciou a arvore
//    {                                                 ///&& verifica se ele tem avo, porque o pai da raiz eh preto
//        ///CASOS EM QUE O TIO ESTA NA ESQUERDA:
//        NoVP* tio;
//        if(no->pai->pai->dir == no->pai)
//        {
//            tio = no->pai->pai->esq;
//            ///CASO 1:SE O TIO FOR VERMELHO, BASTA TROCAR AS CORES DO PAI,AVO E TIO
//            if(tio->cor =='v')
//            {
//                no->pai->cor = 'p';
//                tio->cor = 'p';
//                no->pai->pai->cor = 'v';
//                no=no->pai->pai;
//            }
//            else///CASO 2:ROTACAO SIMPLES OU DUPLA E TROCAR AS CORES NECESSARIAS
//            {
//                if(no == no->pai->esq)//NECESSARIO ROTACAO DUPLA
//                {
//                    no = no->pai;
//                    rotacaoDir(no);
//                }
//                no->pai->cor = 'p';
//                no->pai->pai->cor = 'v';
//                rotacaoEsq(no->pai->pai);
//            }
//        }
//        else ///CASOS EM QUE O TIO ESTA NA DIREITA
//        {
//            tio = no->pai->pai->dir;
//            ///CASO 1: SE O TIO FOR VERMELHO: BASTA RE-COLORIR O PAI, O AVO E O TIO
//            if(tio->cor == 'v')
//            {
//                no->pai->cor = 'p';
//                tio->cor = 'p';
//                no->pai->pai->cor = 'v';
//                no = no->pai->pai;
//            }
//            else///CASO 2:ROTACAO SIMPLES OU DUPLA E TROCAR AS CORES NECESSARIAS
//            {
//                if(no == no->pai->dir)//NECESSARIO ROTACAO DUPLA
//                {
//                    no = no->pai;
//                    rotacaoEsq( no);
//                }
//                no->pai->cor = 'p';
//                no->pai->pai->cor = 'v';
//                rotacaoDir( no->pai->pai);
//            }
//
//        }
//
//    }
//    if(no->pai==nulo)///CASO 0: RAIZ SEMPRE EH PRETA
//    {
//        raiz = no;
//        raiz->cor = 'p';
//    }
//
//}

void ArvoreVP_adaptativa::balanceamentoInsercao(NoVP_adp* no)
{
    NoVP_adp* tio;
    //SE O NO->PAI FOR BLACK, O NO NAO DESBALANCEOU A ARVORE, POIS ELE E INSERIDO VERMELHO
    //SE O NO->PAI FOR RED, E NECESSARIO FAZER O REBALANCEAMENTO DA ARVORE
    while(no->pai->cor == 'v')
    {
        if(no->pai == no->pai->pai->esq)
        {

            tio = no->pai->pai->dir;
            ///CASO 1: SE O TIO FOR VERMELHO: BASTA RE-COLORIR O PAI, O AVO E O TIO DO NO
            if(tio->cor == 'v')
            {
                no->pai->cor = 'p';
                tio->cor = 'p';
                no->pai->pai->cor = 'v';
                no = no->pai->pai;
            }
            ///CASO 2, se o tio for preto: Sera necessario rotacoes e troca de cores
            else
            {
                if(no == no->pai->dir)//verificando se eh necessario rotacao dupla
                {
                    no = no->pai;
                    rotacaoEsq(no);
                }
                no->pai->cor = 'p';
                no->pai->pai->cor = 'v';
                rotacaoDir(no->pai->pai);
            }

        }
        else
        {
            tio = no->pai->pai->esq;
            ///CASO 1: SE O TIO FOR VERMELHO: BASTA RE-COLORIR O PAI, O AVO E O TIO DO NO
            if(tio->cor == 'v')
            {
                no->pai->cor = 'p';
                tio->cor = 'p';
                no->pai->pai->cor = 'v';
                no = no->pai->pai;
            }
            ///CASO 2, se o tio for preto: Sera necessario rotacoes e troca de cores
            else
            {
                if(no == no->pai->esq)//verificando se eh necessario rotacao dupla
                {
                    no = no->pai;
                    rotacaoDir(no);
                }
                no->pai->cor = 'p';
                no->pai->pai->cor = 'v';
                rotacaoEsq(no->pai->pai);
            }

        }

    }
    raiz->cor = 'p'; //PROPRIEDADE 1: A RAIZ SEMPRE E PRETO
}

int ArvoreVP_adaptativa::buscaVP(int chave)
{
    NoVP_adp *aux = raiz;
    while(aux!=nulo && aux!=NULL)
    {
        if((aux->dado.userid) == chave)
        {
//            cout<<endl<<"aki-> "<<chave<<"\t"<<aux->dado.userid<<endl;
            return aux->indice;
        }
        if(chave>aux->dado.userid)
            aux = aux->dir;
        else
            aux = aux->esq;
    }
    return -1;
}


void ArvoreVP_adaptativa::imprimeVP()
{
    if(raiz != NULL)
    {
        printf("\n\n_________________________________________________________________________\n");
        printf("IMPRIMINDO ARVORE VERMELHO PRETO EM ORDEM (ESQ, RAIZ, DIR)\n\n");
        if(raiz == nulo)
            printf("\nArvore Vazia!\n");
        else
        {
            auxImprime(raiz);
cout<<endl;
            Vizualiza_ArvoreRedBlack(raiz);

        }
        printf("\n_________________________________________________________________________\n\n");
    }
}

void ArvoreVP_adaptativa::auxImprime(NoVP_adp* no)
{
    if(no != NULL && no!=nulo)
    {
        auxImprime(no->esq);

        if(no==raiz)
        {
            cout<< "||RAIZ|| ->\t[" << no->dado.userid <<"| "<<no->cor<< "]:{ ";

        }
        else
        {
            cout<< "[" << no->dado.userid <<"| "<<no->cor<< "]:{";
        }
        if(no->esq==nulo)
        {
            cout<<"f_Esquerdo: NULL ";
        }
        else
        {
            cout<<"f_Esquerdo: "<< no->esq->dado.userid<<", ";
        }
        if(no->dir==nulo)
        {
            cout<<"f_Direito: NULL }\n\n";
        }
        else
        {
            cout<<"f_Direito: "<< no->dir->dado.userid<<" }\n\n";
        }
        auxImprime(no->dir);
    }

}

int ArvoreVP_adaptativa::height(NoVP_adp* root)
{
    if(root==nulo||root==NULL)
        return 0;
    int esq = height(root->esq);
    int dir = height(root->dir);
    if(1+esq > 1+dir)
    {
        return 1+esq;
    }
    return 1+dir;
}

/* Function to line by line print level order traversal a tree*/
void ArvoreVP_adaptativa::Vizualiza_ArvoreRedBlack( NoVP_adp* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i, h);
        printf ( "\n" );
    }
}

/* Print nodes at a given level */
void ArvoreVP_adaptativa::printGivenLevel( NoVP_adp* root,int level,int h)
{
    if (root == NULL||root == nulo)
        return ;
    if (level == 1)
    {
//        for(int i=0; i<h; h++)
//            cout<<"\t";
        cout<<"["<<root->dado.userid<<"|"<<root->cor<<"] ";//printf ( "%d " , root->dado);
    }
    else if (level > 1)
    {
        printGivenLevel(root->esq, level-1, h);
        printGivenLevel(root->dir, level-1, h );
    }
}
