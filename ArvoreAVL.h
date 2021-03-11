#define ARVOREAVL_H_INCLUDED
#include "NoAVL.h"

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

public:
    ArvoreAVL();
    ~ArvoreAVL();
    int getRaiz();
    bool vazia();
    void insere(int val);
    bool busca(int val, long int *comparacoes);
    int maior(int a, int b);
    void fatorBalanciado();
};