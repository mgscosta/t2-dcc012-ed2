#ifndef BTREENODE_H
#define BTREENODE_H

#include <iostream>
#include <fstream>

using namespace std;

class BTreeNode
{
private:
    //Vetor com as chaves armazenadas
    int *keys;
    //Valor que define a metade da ordem da árvore
    int minDeg;
    //Vetor de filhos deste nó
    BTreeNode **children;
    //Valor que armazena a quantidade de chaves neste nó
    int storedKeys;
    //Booleano que indentifica se este nó é folha
    bool leaf;
public:
    /**
     * Contrutor da classe
     * 
     * @param int minDeg
     * @param bool leaf
    */
    BTreeNode(int minDeg,bool leaf);

    /**
     * Destrutor da classe
     * 
    */
    ~BTreeNode();

    /**
     * Retorna o vetor de chaves deste nó
     * 
     * @return int*
    */
    int* getkeys();

    /**
     * Retorna o vetor de filhos deste nó
     *
     * @return BTreeNode** 
    */
    BTreeNode** getChildren();

    /**
     * Retorna o número de chaves armazenadas neste nó
     * 
     * @return int
    */
    int getStoredKeys();

    /**
     * Retorna a metade da ordem deste nó
     * 
     * @return int
    */
    int getMinDeg();

    /**
     * Retorna se o nó é uma folha ou não
     * 
     * @return bool
    */
    bool isLeaf();

    /**
     * Retorna uma chave específica deste nó, baseada em sua posição no vetor de chaves deste nó
     * 
     * @param int index
     * @return int
    */
    int getKey(int index);

    /**
     * Retorna um filho deste nó, baseado na sua posição no vetor de filhos
     * 
     * @param int index
     * @return BTreeNode*
    */
    BTreeNode* getChild(int index);

    /**
     * Define/Redefine o número de chaves armazenadas neste nó
     * 
     * @param int storedKeys
     * @return void
    */
    void setStoredKeys(int storedKeys);

    /**
     * Define/Redefine o valor de uma chave armazanada no vetor de chaves deste nó
     * 
     * @param int index
     * @param int key
     * @return void
    */
    void setKey(int index,int key);

    /**
     * Define/Redefine o nó que é filho deste nó
     * 
     * @param int index
     * @param BTreeNode* node
     * @return void
    */
    void setChild(int index,BTreeNode *node);

    /**
     * Retorna o nó em que a chave passada por parâmetro está presente
     * 
     * @param int key
     * @return BTreeNode*
    */
    BTreeNode* search(int key);

    /**
     * Imprime o conteúdo de chaves deste nó e de todos os seus filhos no console
     * 
     * @return void
    */
    void printNodeOnConsole();

    /**
     * Imprime o conteúdo de chaves deste nó e de todos os seus filhos em arquivo
     * 
     * @return void
    */
    void printNodeOnArchive(ofstream &file);

    /**
     * Parte do algoritmo de inserção da árvore caso o nó seja folha, ele insere nó no vetor de chaves, 
     * caso contrário ele faz a busca entre os filhos pela folha correta para inserção, fazendo as devidas repatições 
     * caso um dos nós filhos esteja cheio
     * 
     * @param int key
     * @return void
    */
    void insert(int key);

    /**
     * Realiza a repartição do filho i deste nó, dividindo suas chaves e filhos corretamente
     * 
     * @param int i
     * @param BTreeNode* node
     * @return void
    */
    void split(int i,BTreeNode *node);
};

#endif