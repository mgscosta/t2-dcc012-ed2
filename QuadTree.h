#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
#include <string>
#include "QuadTreeNode.h"
#include "CoordinatesData.h"

using namespace std;

class QuadTree
{
private:
    QuadTreeNode *root;
    void dealocateNodes(QuadTreeNode *root);
    string getDirection(CoordinatesData city,QuadTreeNode *currentNode);
public:
    QuadTree();
    QuadTree(CoordinatesData cityRoot);
    ~QuadTree();

    void insert(CoordinatesData city);
    bool search(CoordinatesData city);
};

#endif