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

void QuadTree::printOnConsole(QuadTreeNode *node,string direction /*= ""*/)
{
    if(node != nullptr)
    {
        printOnConsole(node->getNortheast(),"NE");
        printOnConsole(node->getNorthwest(),"NW");
        if(node->getFather() != nullptr)
        {
            cout << "Quadrante " << direction << " de " << node->getFather()->getCity().getCityName() << ": ";
        }
        else
        {
            cout << "Raiz: ";
        }
        cout << node->getCity().getStateCode() << "," << node->getCity().getCityCode() << "," << node->getCity().getCityName() << "," << node->getLatitude() << "," << node->getLongtude() << "," << node->getCity().isCapital() << endl;
        printOnConsole(node->getSouthwest(),"SW");
        printOnConsole(node->getSoutheast(),"SE");
    }
    else
    {
        return;
    }
}

void QuadTree::printOnArchive(ofstream &file,QuadTreeNode *node,string direction /*= ""*/)
{
    if(node != nullptr)
    {
        printOnArchive(file,node->getNortheast(),"NE");
        printOnArchive(file,node->getNorthwest(),"NW");
        if(node->getFather() != nullptr)
        {
            file << "Quadrante " << direction << " de " << node->getFather()->getCity().getCityName() << ": ";
        }
        else
        {
            file << "Raiz: ";
        }
        file << node->getCity().getStateCode() << "," << node->getCity().getCityCode() << "," << node->getCity().getCityName() << "," << node->getLatitude() << "," << node->getLongtude() << "," << node->getCity().isCapital() << endl;
        printOnArchive(file,node->getSouthwest(),"SW");
        printOnArchive(file,node->getSoutheast(),"SE");
    }
    else
    {
        return;
    }   
}

void QuadTree::printTree(bool archive,string filename /*= ""*/)
{
    if(archive)
    {
        ofstream outfile(filename,ios::app);
        printOnArchive(outfile,this->root);
        outfile << endl;
        cout << "Árvore salva em " << filename << endl;
        outfile.close();
    }
    else
    {
        printOnConsole(this->root);
    }
}

void QuadTree::auxSearchCityCodes(QuadTreeNode *node,float latX,float longX,float latY,float longY,vector<string> &cityCodes)
{
    if(node == nullptr)
    {
        return;
    }
    else
    {
        if((node->getLatitude() >= latX && node->getLatitude() <= latY) && (node->getLongtude() >= longX && node->getLongtude() <= longY))
        {
            cityCodes.push_back(to_string(node->getCity().getCityCode()).substr(0,6));
        }
        auxSearchCityCodes(node->getNortheast(),latX,longX,latY,longY,cityCodes);
        auxSearchCityCodes(node->getNorthwest(),latX,longX,latY,longY,cityCodes);
        auxSearchCityCodes(node->getSouthwest(),latX,longX,latY,longY,cityCodes);
        auxSearchCityCodes(node->getSoutheast(),latX,longX,latY,longY,cityCodes);
    }
}

vector<string> QuadTree::searchForCityCodesOnCoordinates(float latX,float longX,float latY,float longY)
{
    vector<string> cityCodes;
    auxSearchCityCodes(this->root,latX,longX,latY,longY,cityCodes);
    return cityCodes;
}