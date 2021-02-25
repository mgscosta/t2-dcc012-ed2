#include <iostream>
#include <vector>
#include "CoordinatesData.h"
#include "DataReader.h"
#include "QuadTree.h"

using namespace std;

int main()
{
    vector<CoordinatesData*> data;
    DataReader reader;
    data = reader.readCoordinatesDatafromFile("brazil_cities_coordinates.csv");
    QuadTree tree;
    for(int i = 0;i < data.size();i++)
    {
        tree.insert(*data[i]);
    }
    
    return 0;
}