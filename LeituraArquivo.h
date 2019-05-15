#include <string>
#ifndef TRABALHOEDII_LEITURAARQUIVO_H
#define TRABALHOEDII_LEITURAARQUIVO_H
#include "Objeto.h"

#include <fstream>

using namespace std;

class LeituraArquivo {
public:
    LeituraArquivo();
    LeituraArquivo(string nomeArquivoEntrada);
    ~LeituraArquivo();

    Objeto* RandomRead(int qntdeLinhas);
    Objeto Parse(string str);

    int* LerEntrada(string nomeArquivo, int* tamVet);

    void SelecionaArquivo(string nomeArquivo);
    void EscreveDesempenho(string nomeAlgoritmo, int numTrocas, int numComparacoes, double tempoExecucao);

private:
    const string DIRETORIO = "arquivos/";
    string nomeArquivoEntrada;
    ifstream arquivoEntrada;
    ofstream arquivoSaida;
};


#endif //TRABALHOEDII_LEITURAARQUIVO_H
