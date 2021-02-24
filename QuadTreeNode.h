#ifndef QUADTREENODE_H
#define QUADTREENODE_H

#include <iostream>
#include "CoordinatesData.h"

using namespace std;

class QuadTreeNode
{
private:
    QuadTreeNode *father;
    CoordinatesData city;
    QuadTreeNode *northeast;
    QuadTreeNode *northwest;
    QuadTreeNode *southwest;
    QuadTreeNode *southeast;
public:
    QuadTreeNode(CoordinatesData city);
    QuadTreeNode(QuadTreeNode *father,CoordinatesData city);
    ~QuadTreeNode();

    QuadTreeNode* getFather();
    CoordinatesData getCity();
    QuadTreeNode* getNortheast();
    QuadTreeNode* getNorthwest();
    QuadTreeNode* getSouthwest();
    QuadTreeNode* getSoutheast();
    float getLatitude();
    float getLongtude();

    void setNortheast(QuadTreeNode *northeast);
    void setNorthwest(QuadTreeNode *northwest);
    void setSouthwest(QuadTreeNode *southwest);
    void setSoutheast(QuadTreeNode *southeast);
    void setFather(QuadTreeNode *father);
    void setCity(CoordinatesData city);
};

#endif