#ifndef NOHB_H_INCLUDED
#define NOHB_H_INCLUDED

class NohB
{
    private:
    int n; //número de chaves
    NohB **children; //array/vetor de ponteiros que aponta para os filhos
    int *keys; //array com capacidade para n-1 filhos
    int maxO; //ordem da árvore
    bool leaf; //verdadeiro se for folha, falso caso contrario

    public:
    NohB(int i_, bool le_af); //construtor
    NohB *searchNoh(int j_); //busca por nó
    void trvs(); //
    void split(int i, NohB *a_); //separa o filho 'a_' do nó quando ocorre overflow
    void insertFree(int k_); //insere a chave em nó antes de ele estar cheio

    friend class BTree;
};

#endif // NOHB_H_INCLUDED
