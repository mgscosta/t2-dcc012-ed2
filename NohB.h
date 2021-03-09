#ifndef NOHB_H_INCLUDED
#define NOHB_H_INCLUDED

class NohB
{
    private:
    int n; //n�mero de chaves
    NohB **children; //vetor de ponteiros que aponta para os filhos
    int *keys; //array com capacidade para n-1 filhos
    int maxO; //ordem da �rvore
    bool leaf; //verdadeiro se for folha, falso caso contrario

    public:
    NohB(int in, bool le_af); //construtor
    NohB *searchNoh(int jn); //busca por n�
    void cross(); //
    void split(int i, NohB *a1); //separa o filho 'a1' do n� quando ocorre overflow
    void inserti(int k1); //insere a chave em n� antes de ele estar cheio

    friend class ArvB;
};

#endif // NOHB_H_INCLUDED
