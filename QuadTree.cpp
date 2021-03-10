#include "QuadTree.h"

QuadTree::QuadTree()
{
    this->root = nullptr;
}

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

string QuadTree::getDirection(CoordinatesData city,QuadTreeNode *currentNode)
{
    if(city.getLatitude() < currentNode->getLatitude())
    {
        if(city.getLongtude() < currentNode->getLongtude())
        {
            return "SW";
        }
        else
        {
            return "NW";
        }
    }
    else
    {
        if(city.getLongtude() < currentNode->getLongtude())
        {
            return "SE";
        }
        else
        {
            return "NE";
        }
    }
}

void QuadTree::insert(CoordinatesData city)
{
    if(this->root == nullptr)
    {
        this->root = new QuadTreeNode(city);
    }
    else
    {
        QuadTreeNode *node = this->root;
        QuadTreeNode *father = this->root->getFather();
        string direction; 
        while (node != nullptr && city.getCityCode() != node->getCity().getCityCode())
        {
            direction = this->getDirection(city,node);
            father = node;
            if(direction == "SW")
            {
                node = node->getSouthwest();
            }
            else if(direction == "NW")
            {
                node = node->getNorthwest();
            }
            else if(direction == "SE")
            {
                node = node->getSoutheast();
            }
            else
            {
                node = node->getNortheast();
            }
        }
        if(node == nullptr)
        {
            if(direction == "SW")
            {
                father->setSouthwest(new QuadTreeNode(father,city));
            }
            else if(direction == "NW")
            {
                father->setNorthwest(new QuadTreeNode(father,city));
            }
            else if(direction == "SE")
            {
                father->setSoutheast(new QuadTreeNode(father,city));
            }
            else
            {
                father->setNortheast(new QuadTreeNode(father,city));
            }
        }
        else
        {
            cout << "Cidade já presente na árvore" << endl;
        }
    }
}

bool QuadTree::search(CoordinatesData city)
{
    if(this->root == nullptr)
    {
        return false;
    }
    else
    {
        QuadTreeNode *node = this->root;
        QuadTreeNode *father = this->root->getFather();
        string direction; 
        while (node != nullptr && city.getCityCode() != node->getCity().getCityCode())
        {
            direction = this->getDirection(city,node);
            father = node;
            if(direction == "SW")
            {
                node = node->getSouthwest();
            }
            else if(direction == "NW")
            {
                node = node->getNorthwest();
            }
            else if(direction == "SE")
            {
                node = node->getSoutheast();
            }
            else
            {
                node = node->getNortheast();
            }
        }
        
        if(node == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }   
    }
}