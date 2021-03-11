#include "DataReader.h"

DataReader::DataReader(){}

DataReader::~DataReader(){}

bool DataReader::stringToBoolean(string str)
{
    if(str == "FALSE")
    {
        return false;
    }
    else
    {
        return true;
    }
}

vector<CoordinatesData*> DataReader::readCoordinatesDatafromFile(string filename)
{
    ifstream file;
    string line;
    vector<CoordinatesData*> data;

    file.open(filename);

    if(file.is_open())
    {
        getline(file,line);
        while(getline(file,line))
        {
            istringstream dataFromLine(line);
            string stateCode,cityCode,cityName,latitude,longtude,capital;
            getline(dataFromLine,stateCode,',');
            getline(dataFromLine,cityCode,',');
            getline(dataFromLine,cityName,',');
            getline(dataFromLine,latitude,',');
            getline(dataFromLine,longtude,',');
            getline(dataFromLine,capital,',');
            data.push_back(new CoordinatesData(atoi(stateCode.c_str()),atoi(cityCode.c_str()),cityName,stof(latitude),stof(longtude),this->stringToBoolean(capital)));
        }
        file.close();
    }
    else
    {
        cout << "Arquivo não aberto, retornando vector vazio!" << endl;
    }

    return data;
}

vector<HashItem*> DataReader::readPreProcessedCovidDataFromFile(string filename)
{
    ifstream file;
    string line;
    vector<HashItem*> items;

    string key;
    CovidData value;
    file.open(filename);
    if(file.is_open())
    {
        while(getline(file,line))
        {
            if(line == "")
            {
                continue;
            }
            else
            {
                istringstream dataFromLine(line);
                string date,stateInitials,cityName,cityCode,caseCount,deathCount;
                getline(dataFromLine,date,',');
                getline(dataFromLine,stateInitials,',');
                getline(dataFromLine,cityName,',');
                getline(dataFromLine,cityCode,',');
                getline(dataFromLine,caseCount,',');
                getline(dataFromLine,deathCount,',');
                key = cityCode.append(date);
                value.setData(date,stateInitials,cityName,cityCode,atoi(caseCount.c_str()),atoi(deathCount.c_str()));;
                HashItem * item = new HashItem(key, value);
                items.push_back(item);
                
            }
        }
        file.close();
    }
    else
    {
        cout << "Arquivo não aberto, retornando vector vazio!" << endl;
    }

    return items;
}