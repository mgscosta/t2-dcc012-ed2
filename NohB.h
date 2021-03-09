#ifndef NOHB_H_INCLUDED
#define NOHB_H_INCLUDED

class NohB
{
    private:
    int n; //número de chaves
    NohB **children; //vetor de ponteiros que aponta para os filhos
    int *keys; //array com capacidade para n-1 filhos
    int maxO; //ordem da árvore
    bool leaf; //verdadeiro se for folha, falso caso contrario

    public:
    NohB(int in, bool le_af); //construtor
    NohB *searchNoh(int jn); //busca por nó
    void cross(); //
    void split(int i, NohB *a1); //separa o filho 'a1' do nó quando ocorre overflow
    void inserti(int k1); //insere a chave em nó antes de ele estar cheio

    friend class ArvB;
};

#endif // NOHB_H_INCLUDED
