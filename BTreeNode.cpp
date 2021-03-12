#include "BTreeNode.h"

BTreeNode::BTreeNode(int minDeg,bool leaf)
{
    this->minDeg = minDeg;
    this->leaf = leaf;
    this->keys = new int[2 * minDeg - 1];
    for(int i = 0;i < 2 * minDeg - 1;i++)
    {
        this->keys[i] = -1;
    }
    this->children = new BTreeNode *[2 * minDeg];
    for(int i = 0; i < 2 * minDeg;i++)
    {
        this->children[i] = NULL;
    }
    this->storedKeys = 0;
}

BTreeNode::~BTreeNode(){}

int* BTreeNode::getkeys()
{
    return this->keys;
}

BTreeNode** BTreeNode::getChildren()
{
    return this->children;
}

int BTreeNode::getStoredKeys()
{
    return this->storedKeys;
}

int BTreeNode::getMinDeg()
{
    return this->minDeg;
}

bool BTreeNode::isLeaf()
{
    return this->leaf;
}

int BTreeNode::getKey(int index)
{
    return this->keys[index];
}

BTreeNode* BTreeNode::getChild(int index)
{
    return this->children[index];
}

void BTreeNode::setStoredKeys(int storedKeys)
{
    this->storedKeys = storedKeys;
}

void BTreeNode::setKey(int index,int key)
{
    this->keys[index] = key;
}

void BTreeNode::setChild(int index,BTreeNode *node)
{
    this->children[index] = node;
}

BTreeNode* BTreeNode::search(int key)
{
    int i = 0;
    while (i < this->storedKeys && key > this->keys[i])
    {
        i++;
    }

    if(this->keys[i] == key)
    {
        return this;
    }

    if(this->leaf)
    {
        return NULL;
    }

    return this->children[i]->search(key);
}

void BTreeNode::printNode()
{
    int i;
    for(i = 0;i < this->storedKeys;i++)
    {
        if(!this->leaf)
        {
            this->children[i]->printNode();
        }
        cout << " " << this->keys[i];
    }

    if(!this->leaf)
    {
        this->children[i]->printNode();
    }
}

void BTreeNode::split(int i,BTreeNode *node)
{
    BTreeNode *newNode = new BTreeNode(node->getMinDeg(),node->isLeaf());
    newNode->setStoredKeys(this->minDeg - 1);

    for(int j = 0;j < this->minDeg - 1;j++)
    {
        newNode->setKey(j,node->getKey(j + this->minDeg));
    }

    if(!node->isLeaf())
    {
        for(int j = 0;j < this->minDeg;j++)
        {
            newNode->setChild(j,node->getChild(j+this->minDeg));
        }
    }

    node->setStoredKeys(this->minDeg - 1);
    
    for(int j = this->storedKeys - 1; j >= i;j--)
    {
        this->children[j+1] = this->children[j];
    }
    this->children[i+1] = newNode;

    for(int j = this->storedKeys - 1;j >= i;j--)
    {
        this->keys[j+1] = this->keys[j];
    }
    this->keys[i] = node->getKey(this->minDeg - 1);

    this->storedKeys++;
}

void BTreeNode::insert(int key)
{
    int i = this->storedKeys - 1;
    if(this->leaf)
    {
        while (i >= 0 && this->keys[i] > key)
        {
            this->keys[i+1] = this->keys[i];
            i--;
        }
        this->keys[i+1] = key;
        this->storedKeys++;
    }
    else
    {
        while (i >= 0 && this->keys[i] > key)
        {
            i--;
        }
        if(this->children[i+1]->getStoredKeys() == 2 * this->minDeg - 1)
        {
            this->split(i+1,this->children[i+1]);
            if(this->keys[i+1] < key)
            {
                i++;
            }
        }
        this->children[i+1]->insert(key);
    }
}