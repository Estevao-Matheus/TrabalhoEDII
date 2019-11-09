//
// Created by 1513 X-MXTI on 09/07/2019.
//

#include "Usuario.h"

Usuario::Usuario()
{





}


void Usuario::insere(int userid, int movieid, float ratings)
{

    this->userid=userid;
    this->movieid.push_back(movieid);
    this->ratings.push_back(ratings);



}



void Usuario::insereFilme(int movieid, float ratings)
{
    this->movieid.push_back(movieid);
    this->ratings.push_back(ratings);

}

