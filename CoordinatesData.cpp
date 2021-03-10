#include "CoordinatesData.h"

CoordinatesData::CoordinatesData()
{
    this->stateCode = 0;
    this->cityCode = 0;
    this->cityName = "";
    this->latitude = 0;
    this->longtude = 0;
    this->capital = false; 
}

CoordinatesData::CoordinatesData(int stateCode,int cityCode,string cityName,float latitude,float longtude,bool capital)
{
    this->stateCode = stateCode;
    this->cityCode = cityCode;
    this->cityName = cityName;
    this->latitude = latitude;
    this->longtude = longtude;
    this->capital = capital;
}

CoordinatesData::~CoordinatesData(){}

int CoordinatesData::getStateCode()
{
    return this->stateCode;
}

int CoordinatesData::getCityCode()
{
    return this->cityCode;
}

string CoordinatesData::getCityName()
{
    return this->cityName;
}

float CoordinatesData::getLatitude()
{
    return this->latitude;
}

float CoordinatesData::getLongtude()
{
    return this->longtude;
}

bool CoordinatesData::isCapital()
{
    return this->capital;
}

void CoordinatesData::setStateCode(int stateCode)
{
    this->stateCode = stateCode;
}

void CoordinatesData::setCityCode(int cityCode)
{
    this->cityCode = cityCode;
}

void CoordinatesData::setCityName(string cityName)
{
    this->cityName = cityName;
}

void CoordinatesData::setLatitude(float latitude)
{
    this->latitude = latitude;
}

void CoordinatesData::setLongtude(float longtude)
{
    this->longtude = longtude;
}

void CoordinatesData::setCapitalStatus(bool capital)
{
    this->capital = capital;
}