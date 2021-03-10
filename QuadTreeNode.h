#ifndef QUADTREENODE_H
#define QUADTREENODE_H

#include <iostream>
#include "CoordinatesData.h"

using namespace std;

//Classe que implementa os nós da Quad Tree
class QuadTreeNode
{
private:
    //Ponteiro que armazena o endereço do nó pai a este nó, armazena nulo se o nó for uma raiz
    QuadTreeNode *father;
    //Variável que armazena os dados da cidade pertencente a este nó
    CoordinatesData city;
    //Ponteiro que armazena o endereço do nó do quadrante nordeste deste nó
    QuadTreeNode *northeast;
    //Ponteiro que armazena o endereço do nó do quadrante noroeste deste nó
    QuadTreeNode *northwest;
    //Ponteiro que armazena o endereço do nó do quadrante sudoeste deste nó
    QuadTreeNode *southwest;
    //Ponteiro que armazena o endereço do nó do quadrante sudeste deste nó
    QuadTreeNode *southeast;
public:
    /**
     * Construtor da classe
     * 
     * @param CoordinatesData city
    */
    QuadTreeNode(CoordinatesData city);
    /**
     * Contrutor da classe
     * 
     * @param QuadTreeNode* father
     * @param CoordinatesData city
    */
    QuadTreeNode(QuadTreeNode *father,CoordinatesData city);
    /**
     * Destrutor da classe
     * 
    */
    ~QuadTreeNode();

    /**
     * Retorna o nó pai deste nó
     * 
     * @return QuadTreeNode*
    */
    QuadTreeNode* getFather();
    /**
     * Retorna a cidade pertencente a este nó
     * 
     * @return CoordinatesData
    */
    CoordinatesData getCity();
    /**
     * Retorna o nó à nordeste deste nó
     * 
     * @return QuadTreeNode*
    */
    QuadTreeNode* getNortheast();
    /**
     * Retorna o nó à noroeste deste nó
     * 
     * @return QuadTreeNode*
    */
    QuadTreeNode* getNorthwest();
    /**
     * Retorna o nó à sudoeste deste nó
     * 
     * @return QuadTreeNode*
    */
    QuadTreeNode* getSouthwest();
    /**
     * Retorna o nó à sudeste deste nó
     * 
     * @return QuadTreeNode*
    */
    QuadTreeNode* getSoutheast();
    /**
     * Retorna a latitude da cidade pertecente a este nó
     * 
     * @return float
    */
    float getLatitude();
    /**
     * Retorna a longitude da cidade pertecente a este nó
     * 
     * @return float
    */
    float getLongtude();

    /**
     * Define/Redefine o nó à nordeste deste nó
     * 
     * @param QuadTreeNode* northeast
     * @return void
    */
    void setNortheast(QuadTreeNode *northeast);
    /**
     * Define/Redefine o nó à noroeste deste nó
     * 
     * @param QuadTreeNode* northwest
     * @return void
    */
    void setNorthwest(QuadTreeNode *northwest);
    /**
     * Define/Redefine o nó à sudoeste deste nó
     * 
     * @param QuadTreeNode* southwest
     * @return void
    */
    void setSouthwest(QuadTreeNode *southwest);
    /**
     * Define/Redefine o nó à sudeste deste nó
     * 
     * @param QuadTreeNode* southeast
     * @return void
    */
    void setSoutheast(QuadTreeNode *southeast);
    /**
     * Define/Redefine o nó pai deste nó
     * 
     * @param QuadTreeNode* father
     * @return void
    */
    void setFather(QuadTreeNode *father);
    /**
     * Define/Redefine a cidade pertencente a este nó
     * 
     * @param CoordinatesData city
     * @return void
    */
    void setCity(CoordinatesData city);
};

#endif