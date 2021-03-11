#include <iostream>
#include <vector>
#include <time.h>
#include "DataReader.h"
#include "CoordinatesData.h"
#include "QuadTree.h"
#include "HashItem.h"
#include "Hash.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if(argc != 3)
    {
        cout << "ERRO: Esperando os seguintes parâmetros: ./<nome_do_executável> <diretório_dos_datasets> <modo_de_execução>" << endl;
        cout << "0 - Modo de testes" << endl << "1 - Modo de Benchmark" << endl;
    }
    else
    {
        string directory = argv[1];
        DataReader reader;
        /*
        if(directory.back() != '/')
        {
            directory += '/';
        }
        */

        cout << "Trabalho de Estrutura de Dados II - Parte II" << endl;
        cout << "Diretório: " << directory << endl;

        cout << "Importando arquivo de coordenadas do diretório..." << endl;
        vector<CoordinatesData*> coordinatesData = reader.readCoordinatesDatafromFile(directory + "brazil_cities_coordinates.csv");
        cout << "Importando arquivo de dados da COVID-19 do diretório..." << endl;
        vector<HashItem*> covidData = reader.readPreProcessedCovidDataFromFile(directory + "brazil_covid19_cities_processado.csv");

        if(atoi(argv[2]) == 0)
        {
            bool run = true;
            while (run)
            {
                int option;
                int n;
                QuadTree quadTree;
                Hash hashTable;
                vector<int> randomIndex;
                cout << "Menu:" << endl << "1 - Inserção de N cidades da Quad Tree" << endl << "2 - Inserção de N registros na tabela hash" <<
                endl << "3 - Inserção de N chaves na árvore AVL" << endl << "4 - Inserção de N chaves na árvore B" << endl;
                cout << "Selecione uma opção: ";
                cin >> option;

                switch (option)
                {
                case 1:
                    cout << "Selecione o número de registros a ser inseridos na Quad Tree: ";
                    cin >> n;
                    srand(time(NULL));
                    for(int i = 0; i < n; i++)
                    {
                        randomIndex.push_back(rand() % coordinatesData.size());
                    }
                    for(int i = 0; i < randomIndex.size();i++)
                    {
                        quadTree.insert(*coordinatesData[randomIndex[i]]);   
                    }

                    if(n <= 20)
                    {
                        quadTree.printTree(false);
                    }
                    else
                    {
                        quadTree.printTree(true,directory + "saidasQuadTree.txt");
                    }
                    break;
                
                case 2:
                    cout << "Selecione o número de registros a ser inseridos na Tabela Hash: ";
                    cin >> n;
                    srand(time(NULL));
                    for(int i = 0; i < n; i++)
                    {
                        randomIndex.push_back(rand() % covidData.size());
                    }
                    for(int i = 0; i < randomIndex.size();i++)
                    {
                        hashTable.insert(covidData[randomIndex[i]]);   
                    }

                    if(n <= 20)
                    {
                        hashTable.print(false);
                    }
                    else
                    {
                        hashTable.print(true,directory + "saidasHashTable.txt");   
                    }
                    break;
                
                case 3:
                    cout << "Selecione o número de chaves a ser inseridos na Árvore AVL: ";
                    cin >> n;
                    if(n <= 20)
                    {

                    }
                    else
                    {
                        
                    }
                    break;
                
                case 4:
                    cout << "Selecione o número de chaves a ser inseridos na Árvore B: ";
                    cin >> n;
                    if(n <= 20)
                    {

                    }
                    else
                    {
                        
                    }
                    break;           
                
                default:
                    cout << "Encerrando execução..." << endl;
                    run = false;
                    break;
                }
            }
        }
        else if(atoi(argv[2]) == 1)
        {

        }
        else
        {
            cout << "Modo Inválido" << endl << "Encerrando execução..." << endl;
        }
    }
    return 0;
}