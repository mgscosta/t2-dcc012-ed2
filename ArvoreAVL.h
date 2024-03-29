#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include "NoAVL.h"
#include "Hash.h"

using namespace std;

class ArvoreAVL
{
private:
    NoAVL *raiz;
    bool arvAVL;
    NoAVL *auxInsere(NoAVL *p, int val,Hash &table);
    bool auxBusca(NoAVL *p, int id, long int *comparacoes);
    void auxBuscaPorTotaldeCasos(NoAVL *p,string codigoCidade,long int *comparacoes,vector<int> &chaves,Hash &table);
    int alturaNoAVL(NoAVL *p);
    NoAVL *rotacaoSimplesEsquerda(NoAVL *p);
    NoAVL *rotacaoSimplesDireita(NoAVL *p);
    NoAVL *rotacaoDuplaEsquerda(NoAVL *p);
    NoAVL *rotacaoDuplaDireta(NoAVL *p);
    int fatorBalanceamento(NoAVL *p);
    void auxFatorBalanciado(NoAVL *p);
    NoAVL *balancearNo(NoAVL *p);
    void balancearArvore();
    void auxImprimeConsole(NoAVL *no);
    void auxImprimeArquivo(ofstream &arq,NoAVL *no);
public:
    ArvoreAVL();
    ~ArvoreAVL();
    int getRaiz();
    bool vazia();
    void insere(int val, Hash &table);
    bool busca(int val, long int *comparacoes);
    vector<int> buscaPorTotaldeCasos(string codigoCidade,long int *comparacoes,Hash &table);
    int maior(int a, int b);
    void fatorBalanciado();
    void imprime(bool arquivo,string nomeArquivo = "");
};

#endif