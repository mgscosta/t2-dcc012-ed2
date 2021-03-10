#ifndef COORDINATESDATA_H
#define COORDINATESDATA_H

#include <iostream>
#include <string>

using namespace std;

//Classe para armazenar os dados das coordenadas das cidades do Brasil
class CoordinatesData
{
private:
    //Variável para armazenar o código do estado
    int stateCode;
    //Variável para armazenar o código da cidade
    int cityCode;
    //Variável para armazenar o nome da cidade
    string cityName;
    //Variável para armazenar a latitude da cidade
    float latitude;
    //Variável para armazenar o logitude da cidade
    float longtude;
    //Variável que verifica se a cidade é uma capital ou não
    bool capital;
public:
    /**
     * Construtor da classe
     * 
    */
    CoordinatesData();
    /**
     * Construtor da classe
     * 
     * @param int stateCode
     * @param int cityCode
     * @param string cityName
     * @param float latitude
     * @param float longtude
     * @param bool capital
    */
    CoordinatesData(int stateCode,int cityCode,string cityName,float latitude,float longtude,bool capital);
    /**
     * Destrutor da classe
     * 
    */
    ~CoordinatesData();

    /**
     * Retorna o código do estado
     * 
     * @return int
    */
    int getStateCode();
    /**
     * Retorna o código da cidade
     * 
     * @return int
    */
    int getCityCode();
    /**
     * Retorna o nome da cidade
     * 
     * @return string
    */
    string getCityName();
    /**
     * Retorna a latitude da cidade
     * 
     * @return float
    */
    float getLatitude();
    /**
     * Retorna a longitude da cidade
     * 
     * @return float
    */
    float getLongtude();
    /**
     * Retorna verdadeiro se a cidade for uma capital, se não, retorna falso
     * 
     * @return bool
    */
    bool isCapital();

    /**
     * Define/Redefine o código do estado
     * 
     * @param int stateCode
     * @return void
    */
    void setStateCode(int stateCode);
    /**
     * Define/Redefine o código da cidade
     * 
     * @param int cityCode
     * @return void
    */
    void setCityCode(int cityCode);
    /**
     * Define/Redefine o nome da cidade
     * 
     * @param string cityName
     * @return void
    */
    void setCityName(string cityName);
    /**
     * Define/Redefine a latitude da cidade
     * 
     * @param float latitude
     * @return void
    */
    void setLatitude(float latitude);
    /**
     * Define/Redefine a longitude da cidade
     * 
     * @param float longtude
     * @return void
    */
    void setLongtude(float longtude);
    /**
     * Define/Redefine se a cidade é uma capital
     * 
     * @param bool capital
     * @return void
    */
    void setCapitalStatus(bool capital);
};

#endif