#include "BTree.h"

BTree::BTree(int minDeg)
{
    this->root = NULL;
    this->minDeg = minDeg;
}

BTree::~BTree(){}

void BTree::printTree()
{
    if(this->root != NULL)
    {
        this->root->printNode();
    }
}

BTreeNode* BTree::search(int key)
{
    if(this->root == NULL)
    {
        return NULL;
    }
    else
    {
        return this->root->search(key);
    }
}

void BTree::insert(int key)
{
    if(this->root == NULL)
    {
        this->root = new BTreeNode(this->minDeg,true);
        this->root->setKey(0,key);
        this->root->setStoredKeys(1);
    }
    else
    {
        if(this->root->getStoredKeys() == 2 * this->minDeg - 1)
        {
            BTreeNode *newNode = new BTreeNode(this->minDeg,false);
            newNode->setChild(0,this->root);
            newNode->split(0,this->root);

            int i = 0;
            if(newNode->getKey(0) < key)
            {
                i++;
            }
            newNode->getChild(i)->insert(key);

            this->root = newNode;
        }
        else
        {
            this->root->insert(key);
        }
    }
}