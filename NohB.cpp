#include<iostream>
#include "NohB.h"

using namespace std;

NohB::NohB(int i, bool l) {
    maxO = i;
    leaf = l;
    // Aloca memória para o número máximo de chaves
    // e ponteiros para filhos
    keys = new int[2*maxO-1];
    children = new NohB *[2*maxO];

    // Inicia o número de chaves como sendo 0
    n = 0;
}

NohB *NohB::searchNoh(int j_) {

    int i = 0;
    while (i < n && j_ > keys[i]) {
        i++;
    }
    // retorna o nó com o índice que tiver a chave
    if (keys[i] == j_) {
        return this;
    }

    // se o nó não foi encontrado e o nó atual é uma folha:
    if (leaf == true) {
        return NULL;
    }

    // não encontrado a chave no nó, segue pro filho
    return children[i]->searchNoh(j_);
}

void NohB::trvs() {
    // Existem nKeys chaves e nKeys + 1 filhos, prercorre pelas n chaves e os primeiros n filhos
    int i;
    for (i = 0; i < n; i++)
    {
        //se não for folha, percorre pela subárvore do filho children[i] antes de imprimir
        if (leaf == false)
            children[i]->trvs();
        cout << " " << keys[i];
    }

    //  imprime a subárvore do último filho sendo raíz
    if (leaf == false)
        children[i]->trvs();
}

void NohB::split(int i, NohB *a_) {

    ///cria o nó que vai armazenar as maxO - 1 chaves
    NohB *w = new NohB(a_->maxO, a_->leaf);
    w->n = maxO - 1;

    ///copia as últimas maxO - 1
    for (int j = 0; j < maxO-1; j++) {
        w->keys[j] = a_->keys[j+maxO];
    }

    if (a_->leaf == false) {
        for (int j = 0; j < maxO; j++) {
            w->children[j+maxO];
        }
    }

    a_->n = maxO - 1;

    for (int j = n; j > i; j--) {
        children[j+1] = children[j];
    }

    keys[i] = a_->keys[maxO - 1];

    n += 1;
}

void NohB::insertFree(int k_) {

    int i = 0;
    if(leaf == true) {
        while(i >= 0 && keys[i] > k_) {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = k_;
        n += 1;
    }
    else {
        while (i >= 0 && keys[i] > k_) {
            i--;
        }
  
        if (children[i+1]->n == 2 * maxO - 1)  { 
            split(i + 1, children[i+1]); 

            if (keys[i+1] < k_) 
                i++; 
        } 
        children[i+1]->insertFree(k_); 
    } 
}
