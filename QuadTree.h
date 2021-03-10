#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
#include <string>
#include <fstream>
#include "QuadTreeNode.h"
#include "CoordinatesData.h"

using namespace std;

//Classe que implementa a árvore Quad Tree e suas funções
class QuadTree
{
private:
    //Ponteiro que armazena a raiz da árvore
    QuadTreeNode *root;

    /**
     * Função auxiliar do destrutor que desaloca os nós a partir dos nós folhas até a raiz
     * 
     * @param QuadTreeNode* root
     * @return void
    */
    void dealocateNodes(QuadTreeNode *root);

    /**
     * Função auxiliar da busca/inserção que retorna uma string indicando o quadrante em a cidade está localizada 
     * baseada na atual cidade que a busca/inserção está acessando
     * 
     * @param CoordinatesData city
     * @param QuadTreeNode* currentNode
     * @return string
    */
    string getDirection(CoordinatesData city,QuadTreeNode *currentNode);

    /**
     * Função auxiliar que imprime todo o conteúdo da Quad Tree em console
     * 
     * @param QuadTreeNode* node
     * @param string [direction]
     * @return void
    */
    void printOnConsole(QuadTreeNode *node,string direction = "");

    /**
     * Função auxiliar que imprime todo o conteúdo da Quad Tree em arquivo
     * 
     * @param ofstream &file
     * @param QuadTreeNode* node
     * @param string [direction]
     * @return void
    */
    void printOnArchive(ofstream &file,QuadTreeNode *node,string direction = "");
public:
    /**
     * Construtor da classe
     * 
    */
    QuadTree();
    /**
     * Construtor da classe
     * 
     * @param CoordinatesData cityRoot
    */
    QuadTree(CoordinatesData cityRoot);
    /**
     * Destrutor da classe
     * 
    */
    ~QuadTree();

    /**
     * Função de inserção da árvore, ela primeiramente verifica se a raiz é nula para preenchê-la caso positivo, caso contrário, 
     * a ávrore é percorrida baseado-se nas coordenadas de latitude a longitude da cidade a ser inserida, quando um nó nulo é encontrado 
     * ele é preenchido por esta cidade. A inserção não é realizada se duas cidades possuem o mesmo código
     * 
     * @param CoordinatesData city
     * @return void
    */
    void insert(CoordinatesData city);
    /**
     * Função de busca da árvore, a árvore é percorrida de forma semelhante ao método de inserção, quando a busca encontra um nó nulo, ela retorna falso, 
     * caso ela encontre a cidade alvo, ela retorna verdadeiro
     * 
     * @param CoordinatesData city
     * @return bool
    */
    bool search(CoordinatesData city);

    /**
     * Função que imprime a Quad Tree, tendo opções de impressão em console ou arquivo
     * 
     * @param bool archive
     * @param string [filename]
     * @return void
    */
    void printTree(bool archive,string filename = "");
};

#endif