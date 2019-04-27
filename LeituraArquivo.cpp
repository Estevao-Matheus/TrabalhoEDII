#include "LeituraArquivo.h"
#include "Objeto.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <random>

using namespace std;

LeituraArquivo::LeituraArquivo()
{
}

LeituraArquivo::~LeituraArquivo()
{
}

Objeto LeituraArquivo::Parse(string str)
{
    stringstream s(str);
    string sout;
    getline(s, sout, ',');
    int userID = atoi(sout.c_str());
    getline(s, sout, ',');
    int movieID = atoi(sout.c_str());
    getline(s, sout, ',');
    float rating = atof(sout.c_str());
    getline(s, sout, ',');
    long long int timestamp = atoi(sout.c_str());

    Objeto obj(userID, movieID, rating, timestamp);
    return obj;
}

Objeto* LeituraArquivo::RandomRead(int qntdeLinhas, string nomeArquivo)
{
    // Abre o arquivo, de acordo com o nome do diretório e do arquivo;
    const string DIRETORIO = "arquivos/";
    ifstream arq; // ifstream arq(DIRETORIO + NOME_ARQUIVO)
    arq.open(DIRETORIO + nomeArquivo);

    if (arq.is_open()) // verifica se o arquivo foi aberto com sucesso
    {
        arq.seekg(0, ios::end); // pula para o final do arquivo
        int tamanho = arq.tellg(); // tamanho do arquivo TODO: descobrir unidade de medida

        // Cria o vetor de objetos com
        Objeto *vetor = new Objeto[qntdeLinhas];

        int cont = 0;
        while (cont < qntdeLinhas) {
            // gera um número aleatório entre 0 e o tamanho do arquivo
            time_t rawtime;
            srand(time(&rawtime));
            std::mt19937 mt(time(&rawtime)+cont);

            std::uniform_int_distribution<int> linear_i(1, tamanho);
            int aleatorio = linear_i( mt );

            // vai para uma posição aleatória do arquivo e ajusta para o começo da próxima linha
            arq.seekg(aleatorio, ios::beg);
            string strAux;
            getline(arq, strAux, '\n');
            if (arq.eof())
                continue;

            cont++;
            string str;
            getline(arq, str);
            vetor[cont - 1] = Parse(str);
        }
        return vetor;
    }
    else
    {
        cout << "Erro, arquivo nao pode ser aberto" << endl;
    }
    arq.close();
}