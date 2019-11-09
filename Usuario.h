//
// Created by 1513 X-MXTI on 09/07/2019.
//

#ifndef ARVEROB_USUARIO_H
#define ARVEROB_USUARIO_H


#include <vector>

class Usuario {

public:

    int userid;
    std::vector<int> movieid; // array de movieid's que o usuario avaliou;
    std::vector<float>ratings; // array de ratings que o usuario avalioi;
      Usuario();
      void insere(int userid,int movieid,float ratings);
      void insereFilme(int movieid,float ratings);

};



#endif //ARVEROB_USUARIO_H
