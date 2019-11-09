#include "ArvoreVP.h"
#include "Usuario.h"

ArvoreVP::ArvoreVP()
{
    //DEFININDO NO' NULO E DEIXANDO ELE COM A COR PRETA
    nulo = new NoVP;
    nulo->pai = nulo;
    nulo->esq = nulo;
    nulo->dir = nulo;
    nulo->cor = 'p';
    comparacoes = 0;
    copias = 0;
    //INICIANDO A RAIZ COMO NULO
    raiz = nulo;
}

ArvoreVP::~ArvoreVP()
{
    cout<<"DELETANDO ARVORE VERMELHO PRETO...";
    auxDestrutor(raiz);
    delete nulo;
    cout<<"\n";
}

void ArvoreVP::auxDestrutor(NoVP* no)
{
    if(no!=nulo&&no!=NULL)
    {
        NoVP* aux1 = no->esq;
        NoVP* aux2 = no->dir;
        delete no;
        auxDestrutor(aux1);
        auxDestrutor(aux2);
    }
}

void ArvoreVP::zeraConts()
{
    comparacoes = 0;
    copias = 0;
}

void ArvoreVP::rotacaoEsq(NoVP* no)
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

    NoVP * aux = no->dir;
    no->dir = aux->esq;
    copias++;
    comparacoes++;
    if(aux->esq != nulo)
        aux->esq->pai = no;
    aux->pai = no->pai;
    comparacoes++;
    if(no->pai == nulo)
        raiz = aux;
    else if(no == no->pai->esq)
    {
        comparacoes++;
        no->pai->esq = aux;
    }
    else
        no->pai->dir = aux;

    aux->esq = no;
    no->pai = aux;

}

void ArvoreVP::rotacaoDir(NoVP* no)
{
    NoVP* aux = no->esq;
    copias++;
    no->esq = aux->dir;
    comparacoes++;
    if(aux->dir != nulo)
    {
        comparacoes++;
        aux->dir->pai = no;
    }
    aux->pai = no->pai;
    comparacoes++;
    if(no->pai == nulo)
        raiz = aux;
    else if(no == no->pai->esq)
    {
        comparacoes++;
        no->pai->esq = aux;
    }
    else
        no->pai->dir = aux;

    aux->dir = no;
    no->pai = aux;
}

void ArvoreVP::insereVP(Usuario chave)
{
    ///CRIANDO NOVO NO' PARA INSERIR NA ARVORE
    NoVP* novoNo = new NoVP;
    novoNo->cor = 'v';//O NO' SEMPRE EH INSERIDO COM A COR VERMELHA
    novoNo->dado = chave;
    novoNo->pai = nulo;
    novoNo->esq = nulo;
    novoNo->dir = nulo;

    if(raiz==nulo)///Se a arvore estiver vazia...
    {
        comparacoes++;
        raiz = novoNo;//INSERE AKI
    }
    else
        insere_arvBinaria(raiz, novoNo, raiz->pai, chave);///Se a arvore nao estiver vazia, vc insere igual na arvore binaria de busca
//    imprimeVP();
    ///DEPOIS DE INSERIRIR COMO NA ARVORE BINARIA DE BUSCA, EH PRECISO
    ///BALANCEAR A ARVORE, OBEDECENDO AS PROPRIEDADES DA ARVORE VERMELHO E PRETO
    balanceamentoInsercao(novoNo);
}

void ArvoreVP::insere_arvBinaria(NoVP* no, NoVP* novoNo, NoVP* pai, Usuario chave)
{
    if(no==nulo)///CASO BASE, aki inserimos o no'
    {
        comparacoes++;
        novoNo->pai = pai;

        if(novoNo->dado.userid <  pai->dado.userid   )///se no' eh menor que o pai...
        {
            comparacoes++;
            pai->esq = novoNo;///entao o no' eh filho a esquerda
        }
        else if(novoNo->dado.userid > pai->dado.userid) ///se o no' eh maior que o pai
        {
            comparacoes++;
            pai->dir = novoNo;///entao o no' eh filho a direita
        }
        else if(novoNo->dado.userid == pai->dado.userid)
        {
            comparacoes++;
            std::vector<int>::iterator t;
            t=novoNo->dado.movieid.begin();
            int movieid = (*t);

            std::vector<float>::iterator t2;
            t2 = novoNo->dado.ratings.begin();
            float rating = (*t);

            pai->dado.insereFilme(movieid, rating);
        }
    }
    else
    {
        comparacoes++;
        if(novoNo->dado.userid < no->dado.userid)///se o filho eh menor, insere a esquerda
        {
            comparacoes++;
            insere_arvBinaria(no->esq, novoNo, no, chave);
        }

        else ///se o filho eh maior igual, insere a direita
        {
            comparacoes++;
            insere_arvBinaria(no->dir, novoNo, no, chave);
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

void ArvoreVP::balanceamentoInsercao(NoVP* no)
{
    NoVP* tio;
    //SE O NO->PAI FOR BLACK, O NO NAO DESBALANCEOU A ARVORE, POIS ELE E INSERIDO VERMELHO
    //SE O NO->PAI FOR RED, E NECESSARIO FAZER O REBALANCEAMENTO DA ARVORE
    while(no->pai->cor == 'v')
    {
        comparacoes++;
        if(no->pai == no->pai->pai->esq)
        {
            comparacoes++;
            tio = no->pai->pai->dir;
            copias++;
            ///CASO 1: SE O TIO FOR VERMELHO: BASTA RE-COLORIR O PAI, O AVO E O TIO DO NO
            if(tio->cor == 'v')
            {
                comparacoes++;
                no->pai->cor = 'p';
                tio->cor = 'p';
                no->pai->pai->cor = 'v';
                no = no->pai->pai;
            }
            ///CASO 2, se o tio for preto: Sera necessario rotacoes e troca de cores
            else
            {
                comparacoes++;
                comparacoes++;
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
            comparacoes++;
            tio = no->pai->pai->esq;
            copias++;
            ///CASO 1: SE O TIO FOR VERMELHO: BASTA RE-COLORIR O PAI, O AVO E O TIO DO NO
            if(tio->cor == 'v')
            {
                comparacoes++;
                no->pai->cor = 'p';
                tio->cor = 'p';
                no->pai->pai->cor = 'v';
                no = no->pai->pai;
            }
            ///CASO 2, se o tio for preto: Sera necessario rotacoes e troca de cores
            else
            {
                comparacoes++;
                comparacoes++;
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
    comparacoes++;
    raiz->cor = 'p'; //PROPRIEDADE 1: A RAIZ SEMPRE E PRETO
}

NoVP* ArvoreVP::buscaVP(int chave)
{
    NoVP *aux = raiz;
    copias++;
    while(aux!=nulo && aux!=NULL)
    {
        comparacoes++;
        if(aux->dado.userid==chave)
        {
            comparacoes++;
            return aux;
        }
        if(chave>aux->dado.userid)
        {
            comparacoes++;
            aux = aux->dir;
        }
        else
        {
            comparacoes++;
            aux = aux->esq;
        }
    }
    comparacoes++;
    return NULL;
}


void ArvoreVP::imprimeVP()
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

void ArvoreVP::auxImprime(NoVP* no)
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

int ArvoreVP::height(NoVP* root)
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
void ArvoreVP::Vizualiza_ArvoreRedBlack( NoVP* root)
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
void ArvoreVP::printGivenLevel( NoVP* root,int level,int h)
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
