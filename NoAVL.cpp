#include <iostream>
#include "NoAVL.h"

using namespace std;

NoAVL::NoAVL()
{
}

NoAVL::~NoAVL()
{
}

void NoAVL::setEsq(NoAVL *p)
{
    esq = p;
}

void NoAVL::setDir(NoAVL *p)
{
    dir = p;
}
void NoAVL::setInfo(int val)
{
    info = val;
}

NoAVL *NoAVL::getEsq()
{
    return esq;
}

NoAVL *NoAVL::getDir()
{
    return dir;
}

int NoAVL::getInfo()
{
    return info;
}

void NoAVL::setFatorBalanceamento(int val)
{
    fatorBalanceamento = val;
}

int NoAVL::getFatorBalanceamento()
{
    return fatorBalanceamento;
}