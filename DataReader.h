#ifndef DATAREADER_H
#define DATAREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "CoordinatesData.h"

using namespace std;

//Classe resposável pelas funções de leitura e escrita do projeto
class DataReader
{
private:
    /**
     * Função auxiliar responsável por interpretar as strings "TRUE" e "FALSE" em booleano, 
     * caso a string não seja nenhuma das citadas anteriormente o retorno padrão desta função é 
     * true
     * 
     * @param string str
     * @return bool
    */
    bool stringToBoolean(string str);
public:
    /**
     * Construtor da classe
     * 
    */
    DataReader();
    /**
     * Destrutor da classe
     * 
    */
    ~DataReader();

    /**
     * Função que lê o arquivo de coordenadas do projeto e armazena em um vector de ponteiros da classe que 
     * armazena os dados de cada linha do arquivo
     * 
     * @param string filename
     * @return vector<CoordinatesData*>
    */
    vector<CoordinatesData*> readCoordinatesDatafromFile(string filename);
};

#endif