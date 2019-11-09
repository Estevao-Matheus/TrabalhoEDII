#include <iostream>
#include <iostream>
#include "usuario.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include"ArvoreB.h"
#include"ArvoreVP.h"
#include "ArvoreHuffman.h"
#include "LeituraArquivo.h"
#include "usuario.h"

#include <random>
#include <Chrono>

using namespace std;

//Estatisticas a serem armazenadas

double tempoLZW;
double tempoHuffman;
double tamanhoArquivo;

double tempoArvoreB;
double tempoArvoreB2;
double tempoArvoreBbusca;
double tempoArvoreBbusca2;
double tempoArvoreVP;
double tempoArvoreVPbusca;


/********************************** AQUI COMEÇA Compactacao **********************************************/
string parseSinopse(string str)
{
    stringstream s(str);
    string sout, aux;
    char caracter;
    int contAspas = 0;
    getline(s, sout, ',');//Passou da primeira coluna
    /** Percorre at� chegar e armazenar o overview **/
    for(int i = 0; i < 9; i++)
    {
        s>>caracter;
        if(caracter == '"')
        {
            contAspas++;
            getline(s, sout, '"');//Ler at� a pr�xima aspas
            contAspas++;
            aux = sout; //Armazenar o que foi lido para o caso de se ter mais de um conjunto de aspas dentro da mesma coluna
            s>>caracter;//Ler o caracter imediatamente ap�s a aspas
            while(caracter != ',' || (contAspas%2!=0))//Enquanto o caracter lido ap�s a aspas n�o for
            {
                aux = aux + caracter;
                getline(s, sout, '"');
                contAspas++;
                aux = aux + sout;//Armazenar o conte�do lido, j� que pertence a uma mesma coluna
                s>>caracter;
            }
        }
        else if(caracter == ',')
        {
            //Caso de ser uma coluna vazia
            aux = "";
        }
        else
        {
            aux = caracter;//armazenar o caracter lido
            getline(s, sout, ',');
            aux = aux + sout;//concatenar com o resto da coluna
        }
    }
    return aux;
}

string* randomReadSinopse(int qntdeLinhas, string nomeArquivo)
{
    //srand((unsigned)time(0));
    srand ( time(NULL) );

    ///ABRINDO ARQUIVO
    ifstream arq;
    arq.open(nomeArquivo);

    if (arq.is_open()) // verifica se o arquivo foi aberto com sucesso
    {
        ///Obtendo Tamanho
        arq.seekg(0, ios::end); // pula para o final do arquivo
        int tamanho = arq.tellg(); // tamanho do arquivo TODO: descobrir unidade de medida
        tamanhoArquivo = tamanho; //Armazena para estat�stica

        // Cria o vetor de objetos com
        string *vetor = new string[qntdeLinhas];
        //vector<string> vetor;

        int cont = 0;
        int anterior = 0;
        int aleatorio = 0;
        while (cont < qntdeLinhas)
        {
            ///PEGANDO NUMERO ALEATORIO
            while(anterior==aleatorio)///VERIFICA SE ELE ESTA PEGANDO O MESMO NUMERO ALEATORIO SEQUENCIALMENTE
            {
//                unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
//                std::default_random_engine e(seed);
//                std::uniform_int_distribution<int> distr(0, tamanho);
//
//                aleatorio = distr(e);

//                srand((unsigned)time(0)); //para gerar n�meros aleat�rios reais.
//
                aleatorio = rand()%(tamanho+1);
//
//                cout<<aleatorio<<endl;
            }

            arq.seekg(aleatorio, ios::beg);///INDO ATE A POSICAO ALEATORIA
            string strAux;
            getline(arq, strAux, '\n');

            if (!arq.eof())
            {
                cont++;
                string str;
                getline(arq, str);
                vetor[cont - 1] = parseSinopse(str);
                //vetor.push_back(parseSinopse(str));
                anterior = aleatorio;
            }
        }
        arq.close();
        return vetor;
    }
    else
    {
        cout << "Erro, arquivo nao pode ser aberto" << endl;
        system("pause");
    }
    arq.close();
}


void criaHuffman_eGeraArquivoCodificado(string* texto, int sizeVet, string tituloArquivo)
{
    int tabela[256] = {0}; // tabela com posições tipo ASCII pra receber frequencias

    int tamanho = 0;

    for(int i=0; i<sizeVet; i++) // calcula a frenquecia de cada caracter
    {
        for(int j=0; texto[i][j]!='\0'; j++)
        {
            int aux = (int)texto[i][j];
            if(tabela[aux]==0)
                tamanho++;
            tabela[aux] += 1;
        }
    }
    // gera os vetores e atribui os valores de frequencia
    char chave[tamanho];
    int frequencia[tamanho];
    string codigo[256];

    int j =0;
    for(int i=0; i<256; i++)
    {
        if(tabela[i]!=0)
        {
            chave[j] = (char) i;
            frequencia[j] = tabela[i];
            j++;
        }
    }

// daqui pra baixo o codigo gera a arvore e atraves os codigos de cada caractere
    ArvoreHuffman arv(tamanho);
    arv.constroiHuffman(chave, frequencia, tamanho);
    arv.CodigoHuffman(codigo);

    ofstream saida(tituloArquivo, std::ofstream::app);
    for(int i=0; i<sizeVet; i++)
    {
        for(int j=0; texto[i][j]!='\0'; j++)
        {
            int idx = (int)texto[i][j];
            if(!(idx>255||idx<0))
            {
                for(int k=0; codigo[idx][k]!='\0'; k++)
                    saida<<codigo[idx][k];
            }
        }
        saida<<endl;
    }
    saida.close();

}

//Inicializa dicionario com os valores da tabela ASCII
void inicializaDicionario(vector<string> *dic)
{
    string aux = "";
    dic->clear();
    for(int i = 0; i <= 255; i++)
    {
        aux = (char)i;
        dic->push_back(aux);
    }
}

//Fun��o que verifica a presen�a da string no dicion�rio e retorna o �ndice se existir e -1 se n�o
int verificaPresenca_e_RetornaIndice(vector<string> dic, string str)
{
    bool presenca;
    int id;
    std::vector<string>::iterator it;
    it = find (dic.begin(), dic.end(),str);
    if(it!=dic.cend())
    {
        id = distance(dic.begin(), it);
    }
    else
    {
        return -1;
    }
    return id;
}


vector<int> codificaLZW(vector<string> dic, string texto)
{

    vector<int> codigo;
    int i = 0, id = 0;
    string str = "";
    str = str + texto[i];//String come�a com o primeiro s�mbolo do texto
    char c = 'i';
    while(c != '\0')
    {
        i++;
        c = texto[i];
        id = verificaPresenca_e_RetornaIndice(dic, (str+c));
        //verifica se str+c est� no dicion�rio, em caso negativo atualiza str, em negativo, adiciona id de str ao c�digo e str+c ao dicion�rio
        if(id != -1)
            str = str + c;
        else
        {
            id = verificaPresenca_e_RetornaIndice(dic, (str));
            codigo.push_back(id);
            dic.push_back((str+c));
//            cout << str+c << "\t";
            str = c;
        }

    }

    return codigo;
}

//Fun��o que decodifica c�digo LZW para texto, percorrendo o array de valores do c�digo e concatenando o valor dele no dicionario, formando o texto
string decodificaLZW(vector<string> dic, vector<int> codigo)
{
    int id = 0;
    string textoDecodificado = "";
    for(int i = 0; i < codigo.size(); i++)
    {
        textoDecodificado = textoDecodificado + dic[codigo[i]];
    }
    return textoDecodificado;
}

//Fun��o para gravar a sinopse em um arquivo de sa�da
void gravarSinopseSaida(string* sinopses, int tamVetor, string arqSaida)
{
    ofstream saida(arqSaida, std::ofstream::out);
    for(int i = 0; i < tamVetor; i++)
    {
        saida << '"' << sinopses[i] << '"';
        saida<<"\n";
    }
    saida.close();
}

//Fun��o para gravar a sinopse em um arquivo de sa�da usando o vector
void gravarSinopseVectorSaida_LZW(vector<string> sinopses, string arqSaida)
{
    ofstream saida(arqSaida, std::ofstream::out);
    for(int i = 0; i < sinopses.size(); i++)
    {
        saida << '"' << sinopses[i] << '"';
        saida<<"\n";
    }
    saida.close();
}

//Fun��o para gravar o c�digo em um arquivo de sa�da
void gravarCodigoSaida_LZW(vector<int> codigo, string arqSaida)
{
    ofstream saida(arqSaida, std::ofstream::app);
    for(int i = 0; i < codigo.size(); i++)
    {
        saida << "(" << codigo[i] << ")" << "\t";
    }
    saida<<"f \n";
    saida.close();
}

//Gera um arquivo gravando todos os c�digos nele
void gerarArquivoCodigoComprimidoLZW(vector<vector<int>>codigo, string arqSaida, int tam)
{
    for(int k = 0; k < tam; k++)
    {
        gravarCodigoSaida_LZW(codigo[k], arqSaida);
    }
}

double retornaTamanhoComprimido(string entrada)
{
    ifstream arq;
    arq.open(entrada);
    arq.seekg(0, ios::end); // pula para o final do arquivo
    double tamanho = arq.tellg(); // tamanho do arquivo TODO
    arq.close();
    return tamanho;
}

double retornaTaxaCompressao(string entrada)
{
    double tamanho = retornaTamanhoComprimido(entrada);
    cout << endl << "Tamanho do arquivo comprimido: " << tamanho << endl;
    cout << endl << "Tamanho do arquivo original: " << tamanhoArquivo << endl;
    cout << endl << "Taxa de compressao: " << (tamanho/tamanhoArquivo) << endl;
//    arq.close();
    return (double)(tamanho/tamanhoArquivo);
}

//Gera arquivo com estat�sticas
void gravarEstatisticasLZW(string saida, float taxaCompressao, double tamanho)
{
    ofstream arq(saida, fstream::app);
    arq << taxaCompressao << "," << tamanho << "," << tempoLZW << "\n";
    arq.close();
}

void gravarEstatisticasHuffman(string saida, float taxaCompressao, double tamanho)
{
    ofstream arq(saida, fstream::app);
    arq << taxaCompressao << "," << tamanhoArquivo << "," << tempoHuffman << "\n";
    arq.close();
}

void gravarMediaEstatistica(string* arquivos, int tam, string arqSaida)
{
    double somaTaxa = 0.0, somaTempo = 0.0, auxTempo=0.0, auxTaxa=0.0, mediaTempo=0.0, mediaTaxa=0.0;
    unsigned int somaTam = 0, auxTam=0, mediaTam=0;
    string virgula;
    for(int i = 0; i < tam; i++)
    {
        ifstream file(arquivos[i], fstream::in);
        string str;
        getline(file, str);

        stringstream s(str);
        string sout;
        getline(s, sout, ',');
        somaTempo+= atof(sout.c_str());
        getline(s, sout, ',');
        somaTam+= atof(sout.c_str());
        getline(s, sout, ',');
        somaTaxa+= atof(sout.c_str());


//        ifstream file(arquivos[i], fstream::in);
//        file >> auxTempo;
//        somaTempo += auxTempo;
//        file >> virgula;
//        file >> auxTam;
//        somaTam += auxTam;
//        file >> virgula;
//        file >> auxTaxa;
//        somaTaxa += auxTaxa;
        file.close();
        cout << "somaTempo: " << somaTempo << endl;
        cout << "somaTamanho: " << somaTam << endl;
        cout <<  endl << "somaTaxa: " << somaTaxa << endl;


    }

    mediaTaxa = (double)(somaTaxa/5);
    mediaTam = (int)(somaTam/5);
    mediaTempo = (double)(somaTempo/5);
    ofstream arq(arqSaida, fstream::out);
    arq << mediaTaxa << "," << mediaTam << "," << mediaTempo << "\n";
    arq.close();


}

//Orquestrador que gerencia tudo, chamando as fun��es e gerando os nomes dos arquivos de sa�da
void orquestradorCompactacao(string arqRepeticoes, string arqEntrada)
{
    vector<string> dicionario;
    //vector<vector<int>>codigo;
    string* vetorEntradas;
    string* nomesArquivosLZW = new string[5];
    string* nomesArquivosHuffman = new string[5];

    ifstream entrada(arqRepeticoes, fstream::in);

    string strAux, arqSaida = "saida", estatisticaSaida = "estatistica", media = "mediaEstatistica";
    string arqFinal_LZW, estatisticaFinal_LZW, mediaFinal_LZW;
    string arqFinal_Huffman, estatisticaFinal_Huffman, mediaFinal_Huffman;

    getline(entrada, strAux, '\n'); //VERIFICA QUANTIDADE DE REPETICOES DO ARQUIVO DE ENTRADA
    int qtdRepeticao = atoi(strAux.c_str()), tamVetor;
    cout << "Quantidade de Ns" << qtdRepeticao << endl;

    for (int i = 0; i < qtdRepeticao; i++)
    {
        vector<vector<int>>codigo;
        getline(entrada, strAux, '\n');
        tamVetor = atoi(strAux.c_str()); //TAMANHO DO VETOR = TAMANHO INDICADO NA ENTRADA

        //APENAS IMPRESSAO
        cout << "Tamanho do vetor: " << tamVetor << endl;
        string nElementos;
        switch ( i )
        {
        case 0:
            nElementos = "n100";
            break;
        case 1:
            nElementos = "n500";
            break;
        case 2:
            nElementos = "n1000";
            break;
        case 3:
            nElementos = "n5000";
            break;
        case 4:
            nElementos = "n10000";
            break;
        default:
            nElementos = "n0";
            break;
        }

        for(int j = 0; j < 5; j++) //EXECUTAR 5, POR SEREM 5 ENTRADAS
        {
            char c[30];
            snprintf(c, sizeof(c), "%d", j+1);
            arqFinal_LZW = arqSaida + c + nElementos + "_LZW.txt"; //Gerando o nome do arquivo de saida
            estatisticaFinal_LZW = estatisticaSaida + c + nElementos + "_LZW.txt";
            arqFinal_Huffman = arqSaida + c + nElementos + "_Huffman.txt"; //Gerando o nome do arquivo de saida
            estatisticaFinal_Huffman = estatisticaSaida + c + nElementos + "_Huffman.txt";

            vetorEntradas = randomReadSinopse(tamVetor, arqEntrada);

            //codifica todas as sinopses e armazena o tempo gasto
            ///LZW
            inicializaDicionario(&dicionario);
            auto inicio = chrono::high_resolution_clock::now();
            for(int k = 0; k < tamVetor; k++)
            {
                if(k+1%100==0)
                    cout << "Ate " << k << " foi" << endl;
                codigo.push_back(codificaLZW(dicionario, vetorEntradas[k]));/** FAZER VARIAS VEZES **/
            }
            auto resultado = chrono::high_resolution_clock::now() - inicio;
            tempoLZW = chrono::duration_cast<chrono::milliseconds>(resultado).count();
            cout << endl << "Aqui agr" << endl;

            cout << arqFinal_LZW << endl; //ARQfINAL = "TITULO.TXT"
            gerarArquivoCodigoComprimidoLZW(codigo, arqFinal_LZW, tamVetor);
            double taxaCompressaoLZW = retornaTaxaCompressao(arqFinal_LZW);
            gravarEstatisticasLZW(estatisticaFinal_LZW, taxaCompressaoLZW, retornaTamanhoComprimido(arqFinal_LZW));
            nomesArquivosLZW[j] = estatisticaFinal_LZW;

            ///HUFFMAN
            cout << endl << "huffman" << endl;
            inicio = chrono::high_resolution_clock::now();

            criaHuffman_eGeraArquivoCodificado(vetorEntradas, tamVetor, arqFinal_Huffman);

            resultado = chrono::high_resolution_clock::now() - inicio;
            tempoHuffman = chrono::duration_cast<chrono::milliseconds>(resultado).count();
            cout << endl << "Aqui agr2" << endl;

            cout << arqFinal_Huffman << endl;
            double taxaCompressaoHuffman = retornaTaxaCompressao(arqFinal_Huffman);
            gravarEstatisticasHuffman(estatisticaFinal_Huffman, taxaCompressaoHuffman, retornaTamanhoComprimido(arqFinal_Huffman));
            nomesArquivosHuffman[j] = estatisticaFinal_Huffman;
        }
        char c[30];
        snprintf(c, sizeof(c), "%d", i+1);
        mediaFinal_LZW = media + c + "_LZW.txt";
        mediaFinal_Huffman = media + c + "_Huffman.txt";
        //chamar função que pega a média das estatísticas e grava no arquivo
        gravarMediaEstatistica(nomesArquivosLZW, 5, mediaFinal_LZW);
        gravarMediaEstatistica(nomesArquivosHuffman, 5, mediaFinal_Huffman);
//        system("pause");
    }

}

/********************************** AQUI COMEÇA ÁRVORE **********************************************/
//Gera arquivo com estat�sticas
void gravarEstatisticasArvoreB(string saida, unsigned long long int comparacoes, unsigned long long int copias)
{
    ofstream arq(saida, fstream::app);
    arq << comparacoes << "," << copias << "," << tempoArvoreB << "\n";
    arq.close();
}
void gravarEstatisticasArvoreB_Busca(string saida, unsigned long long int comparacoes, unsigned long long int copias)
{
    ofstream arq(saida, fstream::app);
    arq << comparacoes << "," << copias << "," << tempoArvoreBbusca << "\n";
    arq.close();
}
void gravarEstatisticasArvoreB_Busca2(string saida, unsigned long long int comparacoes, unsigned long long int copias)
{
    ofstream arq(saida, fstream::app);
    arq << comparacoes << "," << copias << "," << tempoArvoreBbusca2 << "\n";
    arq.close();
}

//Gera arquivo com estat�sticas
void gravarEstatisticasArvoreVP(string saida, unsigned long long int comparacoes, unsigned long long int copias)
{
    ofstream arq(saida, fstream::app);
    arq << comparacoes << "," << copias << "," << tempoArvoreVP << "\n";
    arq.close();
}
void gravarEstatisticasArvoreVP_busca(string saida, unsigned long long int comparacoes, unsigned long long int copias)
{
    ofstream arq(saida, fstream::app);
    arq << comparacoes << "," << copias << "," << tempoArvoreVPbusca << "\n";
    arq.close();
}

void gravarMediaEstatisticaArvores(string* arquivos, int tam, string arqSaida)
{
    double auxTempo=0.0, mediaTempo=0.0, mediaCompare=0.0, mediaCopia=0.0, somaTempo=0.0;
    unsigned long long int auxCompare=0, auxCopia=0, mediaTam=0, somaCompare = 0, somaCopia = 0;
    string virgula;
    for(int i = 0; i < tam; i++)
    {
        ifstream file(arquivos[i], fstream::in);
        string str;
        getline(file, str);

        stringstream s(str);
        string sout;
        getline(s, sout, ',');
        somaCompare+= atoi(sout.c_str());
        getline(s, sout, ',');
        somaCopia+= atoi(sout.c_str());
        getline(s, sout, ',');
        somaTempo+= atof(sout.c_str());

//        ifstream file(arquivos[i], fstream::in);
//        file >> auxCompare;
//        somaCompare += auxCompare;
//        file >> virgula;
//        file >> auxCopia;
//        somaCopia += auxCopia;
//        file >> virgula;
//        file >> auxTempo;
//        somaTempo += auxTempo;
        file.close();
        cout <<  endl << "Soma Comparacoes: " << somaCompare << endl;
        cout << "Soma Copia: " << somaCopia << endl;
        cout << "Soma Tempo: " << somaTempo << endl;
    }
//    system("pause");

    mediaTempo = (double)(somaTempo/5);
    mediaCompare = (double)(somaCompare/5);
    mediaCopia = (double)(somaCopia/5);
    ofstream arq(arqSaida, fstream::out);
    arq << mediaCompare << "," << mediaCopia << "," << mediaTempo << "\n";
    arq.close();

}


//Orquestrador que gerencia tudo, chamando as fun��es e gerando os nomes dos arquivos de sa�da
void orquestradorArvores(string arqRepeticoes, string arqEntrada)
{
    Usuario *obj;
    int indice;
    unsigned long long nComparacoesVP, nCopiasVP, nComparacoesB, nCopiasB, nComparacoesB2, nCopiasB2, nComparacoesBbusca, nCopiasBbusca, nComparacoesBbusca2, nCopiasBbusca2, nComparcoesBuscaVP, nCopiasBuscaVP;
    char ordem[30];
    /** MANTENHA ATUALIZADO A PRÓXIMA DECLARAÇÃO**/
    ArvoreB arvB(2);//MERAMENTE PARA A CRIAÇÃO DO NOME DO ARQUIVO DE SAIDA DA MEDIA DAS ESTATISTICAS
    ArvoreB arvB2(20);//MERAMENTE PARA A CRIAÇÃO DO NOME DO ARQUIVO DE SAIDA DA MEDIA DAS ESTATISTICAS
    LeituraArquivo leitura;
    string* nomesArquivosArvoreB = new string[5];
    string* nomesArquivosArvoreB2 = new string[5];
    string* nomesArquivosArvoreBbusca = new string[5];
    string* nomesArquivosArvoreBbusca2 = new string[5];
    string* nomesArquivosArvoreVP = new string[5];
    string* nomesArquivosArvoreVP_Busca = new string[5];
    string strAux,strAux2, estatisticaSaida = "estatistica", media = "mediaEstatistica";
    string estatisticaFinal_B, estatisticaFinal_B2, estatisticaFinal_Bbusca, estatisticaFinal_Bbusca2, estatisticaFinal_VP, estatisticaFinal_VP_Busca, mediaFinal_B, mediaFinal_Bbusca, mediaFInal_VP;
    string teste ="teste";

    ifstream entrada(arqRepeticoes, fstream::in);
    getline(entrada, strAux, '\n');
    int qtdRepeticao = atoi(strAux.c_str()), tamVetor;
    cout << "Quantidade de Ns " << qtdRepeticao << endl;
    for(int i = 0; i < qtdRepeticao; i++)
    {
        getline(entrada, strAux, '\n');
        tamVetor = atoi(strAux.c_str()); //TAMANHO DO VETOR = TAMANHO INDICADO NA ENTRADA
        string nElementos;
        switch ( i )
        {
        case 0:
            nElementos = "n1000";
            break;
        case 1:
            nElementos = "n5000";
            break;
        case 2:
            nElementos = "n10000";
            break;
        case 3:
            nElementos = "n50000";
            break;
        case 4:
            nElementos = "n100000";
            break;
        case 5:
            nElementos = "n500000";
        default:
            nElementos = "n0";
            break;
        }
        for(int k = 0; k<5; k++)
        {
            char c[30];
            snprintf(c, sizeof(c), "%d", k+1);
            estatisticaFinal_VP = estatisticaSaida + c + nElementos + "_VP.txt"; //Criacao do nome do arquivo de saida
            estatisticaFinal_VP_Busca = estatisticaSaida + c + nElementos + "_VP_Busca.txt"; //Criacao do nome do arquivo de saida



            obj = leitura.RandomRead(tamVetor, arqEntrada, &indice);

            /**Insere e calcula estatísticas **/
            auto inicioVPinsercao = chrono::high_resolution_clock::now();
            ArvoreVP  arvVP;
            for(int i=0; i<indice; i++)
            {
                arvVP.insereVP(obj[i]);
            }
            auto resultadoVPinsercao = chrono::high_resolution_clock::now() - inicioVPinsercao;

            tempoArvoreVP = chrono::duration_cast<chrono::milliseconds>(resultadoVPinsercao).count();
            nCopiasVP = arvVP.copias;
            nComparacoesVP = arvVP.comparacoes;


            auto inicioBinsercao = chrono::high_resolution_clock::now();
            /** JUNTAMENTE COM ESSA DECLARAÇÃO **/
            ArvoreB arvB(2);
            arvB.zeraConts();
            for(int i=0; i<indice; i++)
            {
                arvB.insere(obj[i]);
            }
            auto resultadoBinsercao = chrono::high_resolution_clock::now() - inicioBinsercao;
            tempoArvoreB = chrono::duration_cast<chrono::milliseconds>(resultadoBinsercao).count();

            auto inicioBinsercao2 = chrono::high_resolution_clock::now();
            /** JUNTAMENTE COM ESSA DECLARAÇÃO **/
            ArvoreB arvB2(20);
            arvB2.zeraConts();
            for(int i=0; i<indice; i++)
            {
                arvB2.insere(obj[i]);
            }
            auto resultadoBinsercao2 = chrono::high_resolution_clock::now() - inicioBinsercao2;
            tempoArvoreB2 = chrono::duration_cast<chrono::milliseconds>(resultadoBinsercao2).count();

            nComparacoesB = arvB.contcomp;
            nCopiasB = arvB.contcop;
            nComparacoesB2 = arvB2.contcomp;
            nCopiasB2 = arvB2.contcop;

            //zera contadores para que possam ser incrementados durante a busca
            arvB.zeraConts();
            arvB2.zeraConts();
            arvVP.zeraConts();

            auto inicioBbusca = chrono::high_resolution_clock::now();
            /** JUNTAMENTE COM ESSA DECLARAÇÃO (BUSCA B) **/
            for(int i=0; i<indice; i++)
            {
                arvB.busca(obj[i].userid);
            }
            auto resultadoBbusca = chrono::high_resolution_clock::now() - inicioBbusca;
            tempoArvoreBbusca = chrono::duration_cast<chrono::milliseconds>(resultadoBbusca).count();

            auto inicioBbusca2 = chrono::high_resolution_clock::now();
            /** JUNTAMENTE COM ESSA DECLARAÇÃO (BUSCA B2)**/
            for(int i=0; i<indice; i++)
            {
                arvB2.busca(obj[i].userid);
            }
            auto resultadoBbusca2 = chrono::high_resolution_clock::now() - inicioBbusca2;
            tempoArvoreBbusca2 = chrono::duration_cast<chrono::milliseconds>(resultadoBbusca2).count();

            auto inicioBuscaVP = chrono::high_resolution_clock::now();
            /** JUNTAMENTE COM ESSA DECLARAÇÃO (BUSCA VP)**/
            for(int i=0; i<indice; i++)
            {
                arvVP.buscaVP(obj[i].userid);
            }
            auto resultadoBuscaVP = chrono::high_resolution_clock::now() - inicioBuscaVP;
            tempoArvoreVPbusca = chrono::duration_cast<chrono::milliseconds>(resultadoBuscaVP).count();


		 //Criacao dos nomes dos arquivos de saida
            snprintf(ordem, sizeof(ordem), "%d", arvB.getOrdem());
            estatisticaFinal_B = estatisticaSaida + c + nElementos + "D_" + ordem + "_B.txt";
            estatisticaFinal_Bbusca = estatisticaSaida + c + nElementos + "D_" + ordem + "_B_Busca.txt";

            snprintf(ordem, sizeof(ordem), "%d", arvB2.getOrdem());
            estatisticaFinal_B2 = estatisticaSaida + c + nElementos + "D_" + ordem + "_B.txt";
            estatisticaFinal_Bbusca2 = estatisticaSaida + c + nElementos + "D_" + ordem + "_B_Busca.txt";


            nComparcoesBuscaVP = arvVP.comparacoes;
            nCopiasBuscaVP = arvVP.copias;

            nComparacoesBbusca = arvB.contcomp;
            nCopiasBbusca = arvB.contcop;

            nComparacoesBbusca2 = arvB2.contcomp;
            nCopiasBbusca2 = arvB2.contcop;

		 //Criar arquivo de sa�da e colocar as estat�sticas nele
            gravarEstatisticasArvoreVP(estatisticaFinal_VP, nComparacoesVP, nCopiasVP);
            gravarEstatisticasArvoreVP_busca(estatisticaFinal_VP_Busca, nComparcoesBuscaVP, nCopiasBuscaVP);

            gravarEstatisticasArvoreB(estatisticaFinal_B, nComparacoesB, nCopiasB);
            gravarEstatisticasArvoreB(estatisticaFinal_B2, nComparacoesB2, nCopiasB2);

            gravarEstatisticasArvoreB_Busca(estatisticaFinal_Bbusca, nComparacoesBbusca, nCopiasBbusca);
            gravarEstatisticasArvoreB_Busca2(estatisticaFinal_Bbusca2, nComparacoesBbusca2, nCopiasBbusca2);

            nomesArquivosArvoreVP[k] = estatisticaFinal_VP;
            nomesArquivosArvoreB[k] = estatisticaFinal_B;
            nomesArquivosArvoreB2[k] = estatisticaFinal_B2;
            nomesArquivosArvoreBbusca[k] = estatisticaFinal_Bbusca;
            nomesArquivosArvoreBbusca2[k] = estatisticaFinal_Bbusca2;
            nomesArquivosArvoreVP_Busca[k] = estatisticaFinal_VP_Busca;
        }
        char c[30];
        snprintf(c, sizeof(c), "%d", i+1);
        snprintf(ordem, sizeof(ordem), "%d", arvB.getOrdem());

        mediaFInal_VP = media + c + "_VP.txt"; //Criacao do nome do arquivo de saida
        gravarMediaEstatisticaArvores(nomesArquivosArvoreVP, 5, mediaFInal_VP);
        mediaFInal_VP = media + c + "_VP_Busca.txt";
	  //Criar arquivo de m�dia das estat�sticas e armazen�-la nele
        gravarMediaEstatisticaArvores(nomesArquivosArvoreVP_Busca,5,mediaFInal_VP);

        mediaFinal_B = media + c + "D_" + ordem + "_B.txt";
        gravarMediaEstatisticaArvores(nomesArquivosArvoreB, 5, mediaFinal_B);
        mediaFinal_B = media + c + "D_" + ordem + "_B_Busca.txt";
        gravarMediaEstatisticaArvores(nomesArquivosArvoreBbusca, 5, mediaFinal_B);

        snprintf(ordem, sizeof(ordem), "%d", arvB2.getOrdem());
        mediaFinal_B = media + c + "D_" + ordem + "_B.txt";
        gravarMediaEstatisticaArvores(nomesArquivosArvoreB2, 5, mediaFinal_B);
        mediaFinal_B = media + c + "D_" + ordem + "_B_Busca.txt";
        gravarMediaEstatisticaArvores(nomesArquivosArvoreBbusca2, 5, mediaFinal_B);

    }

}


int main()
{
    orquestradorArvores("entrada1.txt", "ratings.csv");
    orquestradorCompactacao("entrada2.txt", "movies_metadata.csv");
    return 0;
}
