#ifndef DATAREADER_H
#define DATAREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "CoordinatesData.h"

using namespace std;

class DataReader
{
private:
    bool stringToBoolean(string str);
public:
    DataReader();
    ~DataReader();

    vector<CoordinatesData*> readCoordinatesDatafromFile(string filename);
};

#endif