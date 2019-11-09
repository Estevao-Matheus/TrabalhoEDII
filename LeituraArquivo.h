#include <string>
#ifndef TRABALHOEDII_LEITURAARQUIVO_H
#define TRABALHOEDII_LEITURAARQUIVO_H
#include "Usuario.h"
#include"Objeto.h"
#include"ArvoreVP_adaptativa.h"


using namespace std;

class LeituraArquivo {
public:
    LeituraArquivo();
    ~LeituraArquivo();

    Usuario* RandomRead(int qntdeLinhas, string nomeArquivo, int *indice);
    void Parse(string str, Usuario* vetor, int *cont, int *indice, ArvoreVP_adaptativa *arv);

//private:
//    ArvoreVP_adaptativa arv;

};


#endif //TRABALHOEDII_LEITURAARQUIVO_H
