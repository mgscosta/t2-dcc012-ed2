#include "QuadTree.h"

QuadTree::QuadTree(CoordinatesData cityRoot)
{
    this->root = new QuadTreeNode(cityRoot);
}

void QuadTree::dealocateNodes(QuadTreeNode *root)
{
    if(root != nullptr)
    {
        dealocateNodes(root->getNortheast());
        dealocateNodes(root->getNorthwest());
        dealocateNodes(root->getSouthwest());
        dealocateNodes(root->getSoutheast());
        delete root;
    }
    else
    {
        return;
    }
}

QuadTree::~QuadTree()
{
    this->dealocateNodes(this->root);
}

QuadTreeNode* QuadTree::getDirection(CoordinatesData city,QuadTreeNode *currentNode)
{
    if(city.getLatitude() < currentNode->getLatitude())
    {
        if(city.getLongtude() < currentNode->getLongtude())
        {
            return currentNode->getSouthwest();
        }
        else
        {
            return currentNode->getNorthwest();
        }
    }
    else
    {
        if(city.getLongtude() < currentNode->getLongtude())
        {
            return currentNode->getSoutheast();
        }
        else
        {
            return currentNode->getNortheast();
        }
    }
}

void QuadTree::auxInsert(CoordinatesData city,QuadTreeNode *father,QuadTreeNode *currentNode)
{
    if(currentNode == nullptr)
    {
        currentNode = new QuadTreeNode(father,city);
    }
    else
    {
        QuadTreeNode *direction = this->getDirection(city,currentNode);
        auxInsert(city,currentNode,direction);
    }
}

void QuadTree::insert(CoordinatesData city)
{
    this->auxInsert(city,nullptr,this->root);
}

bool QuadTree::auxSearch(CoordinatesData city,QuadTreeNode *currentNode)
{
    if(currentNode == nullptr)
    {
        return false;
    }
    else
    {
        if(city.getCityCode() == currentNode->getCity().getCityCode())
        {
            return true;
        }
        else
        {
            QuadTreeNode *direction = this->getDirection(city,currentNode);
            auxSearch(city,direction);
        }
    }
}

bool QuadTree::search(CoordinatesData city)
{
    return this->auxSearch(city,this->root);
}