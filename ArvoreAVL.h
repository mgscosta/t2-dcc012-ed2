#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

#include <iostream>
#include <fstream>
#include "NoAVL.h"

using namespace std;

class ArvoreAVL
{
private:
    NoAVL *raiz;
    bool arvAVL;
    NoAVL *auxInsere(NoAVL *p, int val);
    bool auxBusca(NoAVL *p, int id, long int *comparacoes);
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
    void insere(int val);
    bool busca(int val, long int *comparacoes);
    int maior(int a, int b);
    void fatorBalanciado();
    void imprime(bool arquivo,string nomeArquivo = "");
};

#endif