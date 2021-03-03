#include <iostream>
#include "ArvoreAVL.h"

using namespace std;

ArvoreAVL::ArvoreAVL()
{
    raiz = NULL;
    arvAVL = 1;
}

ArvoreAVL::~ArvoreAVL()
{
}

int ArvoreAVL::getRaiz()
{
    if (raiz != NULL)
    {
        return raiz->getInfo();
    }
    else
    {
        cout << "Arvore vazia!" << endl;
        exit(1);
    }
}

bool ArvoreAVL::vazia()
{
    return raiz == NULL;
}

void ArvoreAVL::insere(int val)
{
    raiz = auxInsere(raiz, val);

    if (arvAVL == 1)
    {
        fatorBalanciado();
        balancearArvore();
    }
}

NoAVL *ArvoreAVL::auxInsere(NoAVL *p, int val)
{
    if (p == NULL)
    {
        p = new NoAVL();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if (val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));

    return p;
}

bool ArvoreAVL::busca(int val, long int *comparacoes)
{
    bool aux;
    aux = auxBusca(raiz, val, comparacoes);

    return aux;
}

bool ArvoreAVL::auxBusca(NoAVL *p, int id, long int *comparacoes)
{
    *comparacoes = *comparacoes + 1;
    if (p == NULL)
    {
        return false;
    }
    else if (p->getInfo() == id)
    {
        *comparacoes = *comparacoes + 1;
        return true;
    }
    else if (auxBusca(p->getEsq(), id, comparacoes))
    {
        *comparacoes = *comparacoes + 2; // incrementa 2x comparacoes por causa dos ifs de cima
        return true;
    }
    else
    {
        *comparacoes = *comparacoes + 2; // faz incrementar 2x por causa dos ifs de cima
        return auxBusca(p->getDir(), id, comparacoes);
    }
}

NoAVL *ArvoreAVL::rotacaoSimplesEsquerda(NoAVL *p)
{

    NoAVL *aux = p->getDir();
    p->setDir(aux->getEsq());
    aux->setEsq(p);

    return aux;
}

NoAVL *ArvoreAVL::rotacaoSimplesDireita(NoAVL *p)
{
    NoAVL *aux = p->getEsq();
    p->setEsq(aux->getDir());
    aux->setDir(p);

    return aux;
}

NoAVL *ArvoreAVL::rotacaoDuplaEsquerda(NoAVL *p)
{
    NoAVL *right = p->getDir();
    NoAVL *left = right->getEsq();

    p->setDir(left->getEsq());
    right->setEsq(left->getDir());
    left->setDir(right);
    left->setEsq(p);

    return left;
}

NoAVL *ArvoreAVL::rotacaoDuplaDireta(NoAVL *p)
{
    NoAVL *left = p->getEsq();
    NoAVL *right = left->getDir();

    p->setEsq(right->getDir());
    left->setDir(right->getEsq());
    right->setEsq(left);
    right->setDir(p);

    return right;
}

int ArvoreAVL::alturaNoAVL(NoAVL *p)
{
    int altura_esq = 0;
    int altura_dir = 0;

    if (p->getEsq())
        altura_esq = alturaNoAVL(p->getEsq());

    if (p->getDir())
        altura_dir = alturaNoAVL(p->getDir());

    return maior(altura_dir, altura_esq) + 1;
}

int ArvoreAVL::maior(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int ArvoreAVL::fatorBalanceamento(NoAVL *p)
{
    int fator = 0;

    if (p->getEsq())
        fator += alturaNoAVL(p->getEsq());

    if (p->getDir())
        fator -= alturaNoAVL(p->getDir());

    return fator;
}

void ArvoreAVL::fatorBalanciado()
{
    auxFatorBalanciado(raiz);
}

void ArvoreAVL::auxFatorBalanciado(NoAVL *p)
{
    if (p != NULL)
    {
        p->setFatorBalanceamento(fatorBalanceamento(p));

        auxFatorBalanciado(p->getEsq());
        auxFatorBalanciado(p->getDir());
    }
}

NoAVL *ArvoreAVL::balancearNo(NoAVL *p)
{
    NoAVL *noBalanceado = NULL;

    if (p->getEsq())
        p->setEsq(balancearNo(p->getEsq()));

    if (p->getDir())
        p->setDir(balancearNo(p->getDir()));

    int fator = fatorBalanceamento(p);

    if (fator >= 2)
    {
        if (fatorBalanceamento(p->getEsq()) <= -1)
            noBalanceado = rotacaoDuplaDireta(p);
        else
            noBalanceado = rotacaoSimplesDireita(p);
    }
    else if (fator <= -2)
    {
        if (fatorBalanceamento(p->getDir()) >= 1)
            noBalanceado = rotacaoDuplaEsquerda(p);
        else
            noBalanceado = rotacaoSimplesEsquerda(p);
    }
    else
    {
        noBalanceado = p;
    }
    return noBalanceado;
}

void ArvoreAVL::balancearArvore()
{
    NoAVL *auxRaiz = NULL;
    auxRaiz = balancearNo(raiz);

    if (auxRaiz != raiz)
    {
        raiz = auxRaiz;
    }

    fatorBalanciado();
}
