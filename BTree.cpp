#include <iostream>
#include "NohB.h"
#include "BTree.h"

using namespace std;

BTree::BTree(int o_) {
    root = NULL;
    maxO = o_;
}

void BTree::traverse() {
    if (root != NULL) {
        root->trvs();
    }
}

NohB* BTree::searchN(int ky) {
        //return (root == NULL)? NULL : root->searchN(k);
        if(root == NULL) {
            return NULL;
        }
        else {
            root->searchNoh(ky);
        }
}

void BTree::inserti(int a) {
    if (root == NULL) {
        root = new NohB(maxO, true);
        root->keys[0] = a;
        root->n = 1;
    }
    else {
        //se a raíz estiver cheia
        if (root->n == 2*maxO - 1) {
            NohB *r = new NohB(maxO, false);

            r->children[0] = root;

            r->split(0, root);

            int i = 0;
            if (r->keys[0] < a) {
                i++;
            }

            r->children[i]->insertFree(a);

            root = r;
        }
        else {
            root->insertFree(a);
        }
    }
}
