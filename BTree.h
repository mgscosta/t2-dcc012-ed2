#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include "NohB.h"

class BTree
{
    private:
    NohB *root; // ponteiro a raíz
    int maxO; // ordem mínima

    public:
    // Construtor, passando a ordem como parametro
    BTree(int o_);
    // function to traverse the tree
    void traverse();

    // function to search a key in this tree
    NohB* searchN(int ky);

    void inserti(int a);
};

#endif // BTREE_H_INCLUDED
