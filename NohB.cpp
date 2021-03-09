#include<iostream>
#include "NohB.h"

using namespace std;

NohB::NohB(int in, bool l) {
    maxO = in;
    leaf = l;
    // Aloca memória para o número máximo de chaves
    // e ponteiros para filhos
    keys = new int[2 * maxO - 1];
    children = new NohB *[2 * maxO];

    // Inicia o número de chaves como sendo 0
    n = 0;
}

NohB *NohB::searchNoh(int j1) {

    int i = 0;
    while (i < n && j1 > keys[i]) {
        i++;
    }
    // retorna o nó com o índice que tiver a chave
    if (keys[i] == j1) {
        return this;
    }

    // se o nó não foi encontrado e o nó atual é uma folha:
    if (leaf == true) {
        return NULL;
    }

    // não encontrado a chave no nó, segue pro filho
    return children[i]->searchNoh(j1);
}

void NohB::cross() {
    // Existem nKeys chaves e nKeys + 1 filhos, prercorre pelas n chaves e os primeiros n filhos
    int i;
    for (i = 0; i < n; i++) {
        //se não for folha, percorre pela subárvore do filho children[i] antes de imprimir
        if (leaf == false)
            children[i]->cross();
        cout << " " << keys[i];
    }

    //  imprime a subárvore do último filho sendo raíz
    if (leaf == false)
        children[i]->cross();
}

void NohB::split(int i, NohB *a1) {

    ///cria o nó que vai armazenar as maxO - 1 chaves
    NohB *w = new NohB(a1->maxO, a1->leaf);
    w->n = maxO - 1;

    ///copia as últimas maxO - 1
    for (int j = 0; j < maxO - 1; j++) {
        w->keys[j] = a1->keys[j + maxO];
    }

    if (a1->leaf == false) {
        for (int j = 0; j < maxO; j++) {
            w->children[j + maxO];
        }
    }

    a1->n = maxO - 1;

    for (int j = n; j >= i + 1; j--) {
        children[j + 1] = children[j];
    }

    children[i + 1] = w;

    for(int j = n - 1; j >= i; j--) {
        keys[j + 1] = keys[j];
    }

    keys[i] = a1->keys[maxO - 1];

    n += 1;
}

void NohB::inserti(int k1) {

    int i = n - 1;
    if(leaf == true) {
        while(i >= 0 && keys[i] > k1) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k1;
        n += 1;
    }
    else {
        while (i >= 0 && keys[i] > k1) {
            i--;
        }

        if (children[i + 1]->n == 2 * maxO - 1)  {
            split(i + 1, children[i + 1]);

            if (keys[i + 1] < k1) {
                i++;
            }
        }
        children[i + 1]->inserti(k1);
    }
}
