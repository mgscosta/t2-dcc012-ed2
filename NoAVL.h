
#define NOAVL_H_INCLUDED

class NoAVL
{
private:
    NoAVL *esq;
    NoAVL *dir;
    int info;
    int fatorBalanceamento;

public:
    NoAVL();
    ~NoAVL();
    void setEsq(NoAVL *p);
    void setDir(NoAVL *p);
    void setInfo(int val);
    NoAVL *getEsq();
    NoAVL *getDir();
    int getInfo();
    void setFatorBalanceamento(int val);
    int getFatorBalanceamento();
};
