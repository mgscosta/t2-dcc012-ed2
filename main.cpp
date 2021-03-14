#include <iostream>
#include <vector>
#include <time.h>
#include "DataReader.h"
#include "CoordinatesData.h"
#include "QuadTree.h"
#include "HashItem.h"
#include "Hash.h"
#include "ArvoreAVL.h"
#include "BTree.h"
#include "Benchmark.h"

using namespace std;

void execAVLBenchmark (int nData) {
  vector<int> randomIndex;
  vector<int> cities;
  Hash hashTable;
  ArvoreAVL avl;
  string cityCode;
  long int * comparacoes;
  long int numCasos = 0;
  // for(int i < m (5); i++ {})
  // Inserção
  for(int i=0; i < nData; i++) {
    // avl.insere(rand() % hashTable.getSize());
    // Insere index da tabela Hash na AVL tree
  }
  //S1
  cout << "Digite o código da cidade" << endl;
  cin >> cityCode;
  cities = avl.buscaPorTotaldeCasos(cityCode, comparacoes, hashTable);
  for(int i =0; i < cities.size(); i++) {
      numCasos += hashTable.getItemFromHashKey(cities[i]).getCaseCount();
  }
}

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
        cout << "Criando tabela de referência para inserção e busca em árvore..." << endl;
        Hash tableForTrees;
        for(int i = 0;i < covidData.size();i++)
        {
            tableForTrees.insert(covidData[i]);
        }

        if(atoi(argv[2]) == 0)
        {
            bool run = true;
            while (run)
            {
                int option;
                int n;
                QuadTree quadTree;
                Hash hashTable;
                ArvoreAVL avlTree;
                BTree bTree(31);
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
                    srand(time(NULL));
                    for(int i = 0; i < n; i++)
                    {
                        randomIndex.push_back(rand() % covidData.size());
                    }
                    for(int i = 0; i < randomIndex.size();i++)
                    {
                        avlTree.insere(randomIndex[i],tableForTrees);   
                    }

                    if(n <= 20)
                    {
                        avlTree.imprime(false);
                    }
                    else
                    {
                        avlTree.imprime(true,directory + "saidasAVLTree.txt");
                    }
                    break;
                
                case 4:
                    cout << "Selecione o número de chaves a ser inseridos na Árvore B: ";
                    cin >> n;
                    srand(time(NULL));
                    for(int i = 0; i < n; i++)
                    {
                        randomIndex.push_back(rand() % covidData.size());
                    }
                    for(int i = 0; i < randomIndex.size();i++)
                    {
                        bTree.insert(randomIndex[i],tableForTrees);   
                    }

                    if(n <= 20)
                    {
                        bTree.printTree(false);
                    }
                    else
                    {
                        bTree.printTree(true,directory + "saidasBTree.txt");   
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
            // execAVLBenchmark(10000)
            // execAVLBenchmark(50000)
            // execAVLBenchmark(100000)
            // execAVLBenchmark(500000)
            // execAVLBenchmark(1000000)

            // execB20Benchmark(10000)
            // execB20Benchmark(50000)
            // execB20Benchmark(100000)
            // execB20Benchmark(500000)
            // execB20Benchmark(1000000)

            // execB200Benchmark(10000)
            // execB200Benchmark(50000)
            // execB200Benchmark(100000)
            // execB200Benchmark(500000)
            // execB200Benchmark(1000000)


        }
        else
        {
            cout << "Modo Inválido" << endl << "Encerrando execução..." << endl;
        }
    }
    return 0;
}