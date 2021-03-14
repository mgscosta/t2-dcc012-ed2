#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "BTreeNode.h"
#include "Hash.h"

using namespace std;

class BTree
{
private:
    //Ponteiro da raiz árvore
    BTreeNode *root;
    //Valor que define a metade da ordem da árvore
    int minDeg;
public:
    /**
     * Contrutor da classe
     * 
     * @param int minDeg
    */
    BTree(int minDeg);

    /**
     * Destrutor da classe
     * 
    */
    ~BTree();
    
    /**
     * Imprime todo o conteúdo de chaves da árvore com opção de imprimir em arquivo ou console
     * 
     * @return void
    */
    void printTree(bool archive,string filename = "");

    /**
     * Retorna o nó em que a chave dada está presente ou NULL caso não encontrado
     * 
     * @return BTreeNode*
    */
    BTreeNode* search(int key);

    /**
     * Insere uma chave na árvore caso o nó seja folha, ele insere nó no vetor de chaves, 
     * caso contrário ele faz a busca entre os filhos pela folha correta para inserção, fazendo as devidas repatições 
     * caso um dos nós filhos esteja cheio
     * 
     * @param int key
     * @return void 
    */
    void insert(int key,Hash &table);

    vector<int> searchForTotalCases(string cityCode,long int *comparisons,Hash &table);
};

#endif