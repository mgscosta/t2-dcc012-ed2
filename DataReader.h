#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "HashItem.h"
#include "CovidData.h"

using namespace std;

//Classe com as funções de leitura e exportação de dados em arquivos
class DataReader
{
private:
    
public:
    /**
     * Construtor
     * 
    */
    DataReader();
    /**
     * Destrutor
     * 
    */
    ~DataReader();

    /**
     * Retorna um vector com os dados lidos de cada linha do arquivo pré-processado do Covid-19, a função lê o arquivo ignorando as linhas vazias.
     * 
     * @param string fileName
     * @return vector<CovidData>
    */
    vector<HashItem*> readPreProcessedCovidDataFromFile(string filename);

  
};

