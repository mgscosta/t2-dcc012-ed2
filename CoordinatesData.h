#ifndef COORDINATESDATA_H
#define COORDINATESDATA_H

#include <iostream>
#include <string>

using namespace std;

class CoordinatesData
{
private:
    int stateCode;
    int cityCode;
    string cityName;
    float latitude;
    float longtude;
    bool capital;
public:
    CoordinatesData();
    CoordinatesData(int stateCode,int cityCode,string cityName,float latitude,float longtude,bool capital);
    ~CoordinatesData();

    int getStateCode();
    int getCityCode();
    string getCityName();
    float getLatitude();
    float getLongtude();
    bool isCapital();

    void setStateCode(int stateCode);
    void setCityCode(int cityCode);
    void setCityName(string cityName);
    void setLatitude(float latitude);
    void setLongtude(float longtude);
    void setCapitalStatus(bool capital);
};

#endif