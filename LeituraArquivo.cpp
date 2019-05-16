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
#include <Chrono>

using namespace std;

LeituraArquivo::LeituraArquivo()
{
}

LeituraArquivo::~LeituraArquivo()
{
}

LeituraArquivo::LeituraArquivo(string nomeArquivoEntrada)
{
    this->nomeArquivoEntrada = nomeArquivoEntrada;
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

Objeto* LeituraArquivo::RandomRead(int qntdeLinhas)
{
    // Abre o arquivo, de acordo com o nome do diretório e do arquivo;
    if(nomeArquivoEntrada.empty())
        cout << "Erro: O nome do arquivo não foi especificado." << endl;
    else
        arquivoEntrada.open(DIRETORIO + nomeArquivoEntrada);

    Objeto *vetor = new Objeto[qntdeLinhas];

    if (arquivoEntrada.is_open()) // verifica se o arquivo foi aberto com sucesso
    {
        arquivoEntrada.seekg(0, ios::end); // pula para o final do arquivo
        int tamanho = arquivoEntrada.tellg(); // tamanho do arquivo TODO: descobrir unidade de medida

        // Cria o vetor de objetos com


        int cont = 0;
        while (cont < qntdeLinhas) {
            unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
            std::default_random_engine e(seed);
            std::uniform_int_distribution<int> distr(0, tamanho);

            int aleatorio = distr(e);
            // vai para uma posição aleatória do arquivo e ajusta para o começo da próxima linha
            arquivoEntrada.seekg(aleatorio, ios::beg);
            string strAux;
            getline(arquivoEntrada, strAux, '\n');
            if (arquivoEntrada.eof())
                continue;

            cont++;
            string str;
            getline(arquivoEntrada, str);
            vetor[cont - 1] = Parse(str);
        }

    }
    else
    {
        cout << "Erro, arquivo nao pode ser aberto" << endl;
    }
    arquivoEntrada.close();
    return vetor;
}

void LeituraArquivo::SelecionaArquivo(string nomeArquivo)
{
    this->nomeArquivoEntrada = nomeArquivo;
}

int* LeituraArquivo::LerEntrada(string nomeArquivo, int* tamVet)
{
    ifstream entrada;
    entrada.open(DIRETORIO + nomeArquivo);
    int* vet;
    if(entrada.is_open())
    {
        entrada >> *tamVet;
        vet = new int[*tamVet];
        for(int i =0; i < *tamVet; i++)
            entrada >> vet[i];
    }
    else
    {
        cout << "Ocorreu algum erro ao abrir o arquivo de entrada" << endl;
    }
    entrada.close();
    return vet;
}

void LeituraArquivo::EscreveDesempenho(string nomeAlgoritmo, int numTrocas, int numComparacoes, double tempoExecucao)
{

}