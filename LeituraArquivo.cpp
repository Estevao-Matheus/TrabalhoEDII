#include "LeituraArquivo.h"
#include "usuario.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <Chrono>

#include <vector>
#include <algorithm>
#include "usuario.h"
#include"Objeto.h"
#include"ArvoreVP_adaptativa.h"

using namespace std;

LeituraArquivo::LeituraArquivo()
{
}

LeituraArquivo::~LeituraArquivo()
{
}

void LeituraArquivo::Parse(string str, Usuario* vetor, int *cont, int *indice, ArvoreVP_adaptativa* arv)
{

    stringstream s(str);
    string sout;
    getline(s, sout, ',');
    int userID = atoi(sout.c_str());
    getline(s, sout, ',');
    int movieID = atoi(sout.c_str());
    getline(s, sout, ',');
    float rating = atoi(sout.c_str());
    getline(s, sout, ',');


    bool b = false;

    Objeto obj;
    obj.setUserID(userID);
    obj.setMovieID(movieID);
    obj.setRating(rating);
    int idx = arv->insereVP(obj, *indice);//retorna indice, caso o userId ja estiver inserido

    if(idx!=-1) //se user ID tiver inserido insere somente movieID e rating
    {
        b=true;
        std::vector<int>::iterator it;
        it = find (vetor[idx].movieid.begin(), vetor[idx].movieid.end(), movieID);
        if(!(it!=vetor[idx].movieid.end()))
        {
            *cont = (*cont) +1;
            vetor[idx].insereFilme(movieID, rating);
        }

    }

    if(!b) // senão é criado um novo Usuario
    {
        *cont = (*cont) +1;
        *indice = (*indice)+1;
        Usuario temp;
        temp.insere(userID, movieID, rating);
        vetor[(*indice)-1] =  temp;
    }

}

Usuario* LeituraArquivo::RandomRead(int qntdeLinhas, string nomeArquivo, int *indice)
{
    *indice = 0;
    ArvoreVP_adaptativa *arv = new ArvoreVP_adaptativa;
    ///ABRINDO ARQUIVO
    ifstream arq;
    arq.open(nomeArquivo);

    srand ( time(NULL) );

    if (arq.is_open()) // verifica se o arquivo foi aberto com sucesso
    {
        ///Obtendo Tamanho
        arq.seekg(0, ios::end); // pula para o final do arquivo
        int tamanho = arq.tellg(); // tamanho do arquivo TODO: descobrir unidade de medida
//        cout<<tamanho<<endl<<(int)tamanho/40000<<endl<<endl;

        // Cria o vetor de objetos com
        Usuario *vetor = new Usuario[qntdeLinhas];


        int cont = 0;
        int anterior = 0;
        int aleatorio = 0;
        while (cont < qntdeLinhas)
        {
            if(cont%1000==0)
            {
                cout<<"ja inseriu "<<cont<<"..."<<endl;
            }
            ///PEGANDO NUMERO ALEATORIO
            while(anterior==aleatorio)///VERIFICA SE ELE ESTA PEGANDO O MESMO NUMERO ALEATORIO SEQUENCIALMENTE
            {
//                unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
//                std::default_random_engine e(seed);
//                std::uniform_int_distribution<int> distr(0, tamanho);
//
//                aleatorio = distr(e);
                int auxAleatorio = rand()%17730;
                aleatorio = rand()%(tamanho+1);
                aleatorio = auxAleatorio*aleatorio;
//                cout<<"\t"<<aleatorio<<endl;
//                if(aleatorio>40000)
//                    system("pause");
            }

            arq.seekg(aleatorio, ios::beg);///INDO ATE A POSICAO ALEATORIA
            string strAux;
            getline(arq, strAux, '\n');

            if (!arq.eof())
            {
                string str;
                getline(arq, str);
                Parse(str, vetor, &cont, indice, arv);
                anterior = aleatorio;
            }
        }
        arq.close();
        delete arv;
        return vetor;
    }
    else
    {
        cout << "Erro, arquivo nao pode ser aberto" << endl;
        system("pause");
    }
    arq.close();

}
