#include <iostream>
#include "ArvB.h"
using namespace std;

ArvB::ArvB(int o) {
    cout << "entrou no construtor" << endl;
    root = NULL;
    maxO = o;
    cout << "árvore criada" << endl;
}

void ArvB::cross() {
    if (root != NULL) {
        root->cross();
    }
}

NohB* ArvB::searchNoh(int k1) {
        //return (root == NULL)? NULL : root->searchNoh(k1);
        if(root == NULL) {
            return NULL;
        }
        else {
            root->searchNoh(k1);
        }
}

void ArvB::inserti(int a1) {
    if (root == NULL) {
        root = new NohB(maxO, true);
        root->keys[0] = a1;
        root->n = 1;
    }
    else {
        //se a raíz estiver cheia
        if (root->n == (2 * maxO) - 1) {
            NohB *r = new NohB(maxO, false);

            r->children[0] = root;

            r->split(0, root);

            int i = 0;
            if (r->keys[0] < a1) {
                i++;
            }

            r->children[i]->inserti(a1);

            root = r;
        }
        else {
            root->inserti(a1);
        }
    }
}
