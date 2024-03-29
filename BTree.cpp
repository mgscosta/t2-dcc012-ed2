#include "BTree.h"

BTree::BTree(int minDeg)
{
    this->root = NULL;
    this->minDeg = minDeg;
}

BTree::~BTree(){}

void BTree::printTree(bool archive,string filename/*= ""*/)
{
    if(this->root != NULL)
    {
        if(archive)
        {
            ofstream outfile(filename,ios::app);
            this->root->printNodeOnArchive(outfile);
            cout << "Árvore salva em " << filename << endl;
            outfile.close();
        }
        else
        {
            this->root->printNodeOnConsole();
        }
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

void BTree::insert(int key,Hash &table)
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
            if(table.getItemFromHashKey(newNode->getKey(0)).getCityCode() <= table.getItemFromHashKey(key).getCityCode() && table.getItemFromHashKey(newNode->getKey(0)).getDate() < table.getItemFromHashKey(key).getDate())
            {
                i++;
            }
            newNode->getChild(i)->insert(key,table);

            this->root = newNode;
        }
        else
        {
            this->root->insert(key,table);
        }
    }
}

vector<int> BTree::searchForTotalCases(string cityCode,long int *comparisons,Hash &table)
{
    vector<int> keys;
    *comparisons = *comparisons + 1;
    if(this->root == NULL)
    {
        return keys;
    }
    else
    {
        this->root->searchForTotalCases(cityCode,comparisons,keys,table);
        return keys;
    }
}