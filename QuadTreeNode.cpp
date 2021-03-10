#include "QuadTreeNode.h"

QuadTreeNode::QuadTreeNode(CoordinatesData city)
{
    this->father = nullptr;
    this->city = city;
    this->northeast = nullptr;
    this->northwest = nullptr;
    this->southwest = nullptr;
    this->southeast = nullptr;
}

QuadTreeNode::QuadTreeNode(QuadTreeNode *father,CoordinatesData city)
{
    this->father = father;
    this->city = city;
    this->northeast = nullptr;
    this->northwest = nullptr;
    this->southwest = nullptr;
    this->southeast = nullptr;
}

QuadTreeNode::~QuadTreeNode(){}

QuadTreeNode* QuadTreeNode::getFather()
{
    return this->father;
}

CoordinatesData QuadTreeNode::getCity()
{
    return this->city;
}

QuadTreeNode* QuadTreeNode::getNortheast()
{
    return this->northeast;
}

QuadTreeNode* QuadTreeNode::getNorthwest()
{
    return this->northwest;
}

QuadTreeNode* QuadTreeNode::getSouthwest()
{
    return this->southwest;
}

QuadTreeNode* QuadTreeNode::getSoutheast()
{
    return this->southeast;
}

float QuadTreeNode::getLatitude()
{
    return this->city.getLatitude();
}

float QuadTreeNode::getLongtude()
{
    return this->city.getLongtude();
}

void QuadTreeNode::setNortheast(QuadTreeNode *northeast)
{
    this->northeast = northeast;
}

void QuadTreeNode::setNorthwest(QuadTreeNode *northwest)
{
    this->northwest = northwest;
}

void QuadTreeNode::setSouthwest(QuadTreeNode *southwest)
{
    this->southwest = southwest;
}

void QuadTreeNode::setSoutheast(QuadTreeNode *southeast)
{
    this->southeast = southeast;
}

void QuadTreeNode::setFather(QuadTreeNode *father)
{
    this->father = father;
}

void QuadTreeNode::setCity(CoordinatesData city)
{
    this->city = city;
}