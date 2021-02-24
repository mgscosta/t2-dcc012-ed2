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
    QuadTree *tree = new QuadTree(*data[0]);
    for(int i = 1;i < data.size();i++)
    {
        tree->insert(*data[i]);
    }
    
    return 0;
}