#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
#include "QuadTreeNode.h"
#include "CoordinatesData.h"

using namespace std;

class QuadTree
{
private:
    QuadTreeNode *root;
    void dealocateNodes(QuadTreeNode *root);
    QuadTreeNode* getDirection(CoordinatesData city,QuadTreeNode *currentNode);
    void auxInsert(CoordinatesData city,QuadTreeNode *father,QuadTreeNode *currentNode);
    bool auxSearch(CoordinatesData city,QuadTreeNode *currentNode);
public:
    QuadTree(CoordinatesData cityRoot);
    ~QuadTree();

    void insert(CoordinatesData city);
    bool search(CoordinatesData city);
};

#endif