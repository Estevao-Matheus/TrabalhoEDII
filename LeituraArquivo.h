#include <string>
#ifndef TRABALHOEDII_LEITURAARQUIVO_H
#define TRABALHOEDII_LEITURAARQUIVO_H
#include "Objeto.h"

#include <fstream>

using namespace std;

class LeituraArquivo {
public:
    LeituraArquivo();
    LeituraArquivo(string nomeArquivo);
    ~LeituraArquivo();

    Objeto* RandomRead(int qntdeLinhas);
    Objeto Parse(string str);

    void SelecionaArquivo(string nomeArquivo);

private:
    const string DIRETORIO = "arquivos/";
    string nomeArquivo;
    ifstream arquivo;

};


#endif //TRABALHOEDII_LEITURAARQUIVO_H
