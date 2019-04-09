#include <string>
#ifndef TRABALHOEDII_LEITURAARQUIVO_H
#define TRABALHOEDII_LEITURAARQUIVO_H
#include "Objeto.h"

using namespace std;

class LeituraArquivo {
public:
    LeituraArquivo();
    ~LeituraArquivo();

    Objeto* RandomRead(int qntdeLinhas, string nomeArquivo);
    Objeto Parse(string str);

};


#endif //TRABALHOEDII_LEITURAARQUIVO_H
