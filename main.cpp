#include <iostream>
#include <iomanip>
#include <fstream>
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

void execAVLBenchmark(string directory,int nData,Hash &table,string cityCode,vector<string> &cityCodes)
{
    ofstream intro(directory + "saida.txt",ios::app);
    DataReader reader;
    long int s1CompNumber[5];
    long int s2CompNumber[5];
    double insertionTime[5];
    double compTime[5];

    intro << "AVL TREE - N: " << nData << endl;
    intro << "Número de casos S1,Número de casos S2,Comparações S1,Comparações S2,Tempo de execução da inserção,Tempo de execução da busca" << endl;
    intro.close();

    for(int i = 0;i < 5;i++)
    {
        srand(i);
        ArvoreAVL tree;
        Benchmark bench;
        long int comparisons = 0;
        int numCases = 0;

        cout << "Inserção " << i << " N " << nData << endl;
        bench.setStartTimeAsNow();
        for(int j = 0;j < nData;j++)
        {
            tree.insere(rand() % table.getSize(),table);
        }
        bench.setEndTimeAsNow();
        bench.generateInsertionRuntime();

        cout << "Busca " << i << " N " << nData << endl;
        bench.setStartTimeAsNow();
        vector<int> data = tree.buscaPorTotaldeCasos(cityCode,&comparisons,table);
        bench.setS1CompNumber(comparisons);
        comparisons = 0;
        for(int j = 0;j < data.size();j++)
        {
            numCases += table.getItemFromHashKey(data[j]).getCaseCount();
        }
        bench.setS1NumCases(numCases);
        numCases = 0;
        for(int j = 0;j < cityCodes.size();j++)
        {
            data = tree.buscaPorTotaldeCasos(cityCodes[j],&comparisons,table);
            for(int k = 0; k < data.size();k++)
            {
                numCases += table.getItemFromHashKey(data[k]).getCaseCount();
            }
        }
        bench.setS2CompNumber(comparisons);
        bench.setS2NumCases(numCases);
        bench.setEndTimeAsNow();
        bench.generateSearchRuntime();
        s1CompNumber[i] = bench.getS1CompNumber();
        s2CompNumber[i] = bench.getS2CompNumber();
        insertionTime[i] = bench.getInsertionRuntime();
        compTime[i] = bench.getSearchRuntime();
        reader.exportBenchmarkDataToFile(bench,directory + "saida.txt");
    }
    long int averageS1Comp = (s1CompNumber[0] + s1CompNumber[1] + s1CompNumber[2] + s1CompNumber[3] + s1CompNumber[4])/5;
    long int averageS2Comp = (s2CompNumber[0] + s2CompNumber[1] + s2CompNumber[2] + s2CompNumber[3] + s2CompNumber[4])/5;
    double averageInsertionTime = (insertionTime[0] + insertionTime[1] + insertionTime[2] + insertionTime[3] + insertionTime[4])/5;
    double averageCompTime = (compTime[0] + compTime[1] + compTime[2] + compTime[3] + compTime[4])/5;

    ofstream outro(directory + "saida.txt",ios::app);
    outro << "MÉDIAS: Comparações S1,Comparações S2,Tempo de inserção,Tempo de busca" << endl;
    outro << fixed << setprecision(2) << averageS1Comp << "," << averageS2Comp << "," << averageInsertionTime << "," << averageCompTime << endl;
    outro << endl;
    outro.close();
}

void execBTreeBenchmark(int d,string directory,int nData,Hash &table,string cityCode,vector<string> &cityCodes)
{
    ofstream intro(directory + "saida.txt",ios::app);
    DataReader reader;
    long int s1CompNumber[5];
    long int s2CompNumber[5];
    double insertionTime[5];
    double compTime[5];

    intro << "B TREE D " << d << " - N: " << nData << endl;
    intro << "Número de casos S1,Número de casos S2,Comparações S1,Comparações S2,Tempo de execução da inserção,Tempo de execução da busca" << endl;
    intro.close();

    for(int i = 0;i < 5;i++)
    {
        srand(i);
        BTree tree(d);
        Benchmark bench;
        long int comparisons = 0;
        int numCases = 0;
        
        cout << "Inserção " << i << " N " << nData << endl;
        bench.setStartTimeAsNow();
        for(int j = 0;j < nData;j++)
        {
            tree.insert(rand() % table.getSize(),table);
        }
        bench.setEndTimeAsNow();
        bench.generateInsertionRuntime();

        cout << "Busca " << i << " N " << nData << endl;
        bench.setStartTimeAsNow();
        vector<int> data = tree.searchForTotalCases(cityCode,&comparisons,table);
        bench.setS1CompNumber(comparisons);
        comparisons = 0;
        for(int j = 0;j < data.size();j++)
        {
            numCases += table.getItemFromHashKey(data[j]).getCaseCount();
        }
        bench.setS1NumCases(numCases);
        numCases = 0;
        for(int j = 0;j < cityCodes.size();j++)
        {
            data = tree.searchForTotalCases(cityCodes[j],&comparisons,table);
            for(int k = 0; k < data.size();k++)
            {
                numCases += table.getItemFromHashKey(data[k]).getCaseCount();
            }
        }
        bench.setS2CompNumber(comparisons);
        bench.setS2NumCases(numCases);
        bench.setEndTimeAsNow();
        bench.generateSearchRuntime();
        s1CompNumber[i] = bench.getS1CompNumber();
        s2CompNumber[i] = bench.getS2CompNumber();
        insertionTime[i] = bench.getInsertionRuntime();
        compTime[i] = bench.getSearchRuntime();
        reader.exportBenchmarkDataToFile(bench,directory + "saida.txt");
    }
    long int averageS1Comp = (s1CompNumber[0] + s1CompNumber[1] + s1CompNumber[2] + s1CompNumber[3] + s1CompNumber[4])/5;
    long int averageS2Comp = (s2CompNumber[0] + s2CompNumber[1] + s2CompNumber[2] + s2CompNumber[3] + s2CompNumber[4])/5;
    double averageInsertionTime = (insertionTime[0] + insertionTime[1] + insertionTime[2] + insertionTime[3] + insertionTime[4])/5;
    double averageCompTime = (compTime[0] + compTime[1] + compTime[2] + compTime[3] + compTime[4])/5;

    ofstream outro(directory + "saida.txt",ios::app);
    outro << "MÉDIAS: Comparações S1,Comparações S2,Tempo de inserção,Tempo de busca" << endl;
    outro << fixed << setprecision(2) << averageS1Comp << "," << averageS2Comp << "," << averageInsertionTime << "," << averageCompTime << endl;
    outro << endl;
    outro.close();   
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        cout << "ERRO: Esperando os seguintes parâmetros: ./<nome_do_executável> <diretório_dos_datasets> <modo_de_execução>" << endl;
        cout << "0 - Modo de testes" << endl
             << "1 - Modo de Benchmark" << endl;
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
        vector<CoordinatesData *> coordinatesData = reader.readCoordinatesDatafromFile(directory + "brazil_cities_coordinates.csv");
        cout << "Importando arquivo de dados da COVID-19 do diretório..." << endl;
        vector<HashItem *> covidData = reader.readPreProcessedCovidDataFromFile(directory + "brazil_covid19_cities_processado.csv");
        cout << "Criando tabela de referência para inserção e busca em árvore..." << endl;
        Hash tableForTrees;
        for (int i = 0; i < covidData.size(); i++)
        {
            tableForTrees.insert(covidData[i]);
        }

        if (atoi(argv[2]) == 0)
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
                cout << "Menu:" << endl
                     << "1 - Inserção de N cidades da Quad Tree" << endl
                     << "2 - Inserção de N registros na tabela hash" << endl
                     << "3 - Inserção de N chaves na árvore AVL" << endl
                     << "4 - Inserção de N chaves na árvore B" << endl;
                cout << "Selecione uma opção: ";
                cin >> option;

                switch (option)
                {
                case 1:
                    cout << "Selecione o número de registros a ser inseridos na Quad Tree: ";
                    cin >> n;
                    srand(time(NULL));
                    for (int i = 0; i < n; i++)
                    {
                        randomIndex.push_back(rand() % coordinatesData.size());
                    }
                    for (int i = 0; i < randomIndex.size(); i++)
                    {
                        quadTree.insert(*coordinatesData[randomIndex[i]]);
                    }

                    if (n <= 20)
                    {
                        quadTree.printTree(false);
                    }
                    else
                    {
                        quadTree.printTree(true, directory + "saidasQuadTree.txt");
                    }
                    break;

                case 2:
                    cout << "Selecione o número de registros a ser inseridos na Tabela Hash: ";
                    cin >> n;
                    srand(time(NULL));
                    for (int i = 0; i < n; i++)
                    {
                        randomIndex.push_back(rand() % covidData.size());
                    }
                    for (int i = 0; i < randomIndex.size(); i++)
                    {
                        hashTable.insert(covidData[randomIndex[i]]);
                    }

                    if (n <= 20)
                    {
                        hashTable.print(false);
                    }
                    else
                    {
                        hashTable.print(true, directory + "saidasHashTable.txt");
                    }
                    break;

                case 3:
                    cout << "Selecione o número de chaves a ser inseridos na Árvore AVL: ";
                    cin >> n;
                    srand(time(NULL));
                    for (int i = 0; i < n; i++)
                    {
                        randomIndex.push_back(rand() % covidData.size());
                    }
                    for (int i = 0; i < randomIndex.size(); i++)
                    {
                        avlTree.insere(randomIndex[i], tableForTrees);
                    }

                    if (n <= 20)
                    {
                        avlTree.imprime(false);
                    }
                    else
                    {
                        avlTree.imprime(true, directory + "saidasAVLTree.txt");
                    }
                    break;

                case 4:
                    cout << "Selecione o número de chaves a ser inseridos na Árvore B: ";
                    cin >> n;
                    srand(time(NULL));
                    for (int i = 0; i < n; i++)
                    {
                        randomIndex.push_back(rand() % covidData.size());
                    }
                    for (int i = 0; i < randomIndex.size(); i++)
                    {
                        bTree.insert(randomIndex[i], tableForTrees);
                    }

                    if (n <= 20)
                    {
                        bTree.printTree(false);
                    }
                    else
                    {
                        bTree.printTree(true, directory + "saidasBTree.txt");
                    }
                    break;

                default:
                    cout << "Encerrando execução..." << endl;
                    run = false;
                    break;
                }
            }
        }
        else if (atoi(argv[2]) == 1)
        {
            cout << "Montando Quad Tree para pesquisa em coordenadas..." << endl;
            QuadTree treeForSearch;
            for(int i = 0;i < coordinatesData.size();i++)
            {
                treeForSearch.insert(*coordinatesData[i]);
            }

            string cityCode;
            cout << "Digite o código da cidade que deseja realizar a pesquisa (Código deve ter apenas os seis primeiros digitos): ";
            cin >> cityCode;

            float coords[4];
            cout << "Digite as coordenadas para a pesquisa por latitude e logitude" << endl;
            cout << "Latitude X: ";
            cin >> coords[0];
            cout << "Longitude X: ";
            cin >> coords[1];
            cout << "Latitude Y ";
            cin >> coords[2];
            cout << "Longitude Y: ";
            cin >> coords[3];

            vector<string> cityCodes = treeForSearch.searchForCityCodesOnCoordinates(coords[0],coords[1],coords[2],coords[3]);

            execAVLBenchmark(directory,10000,tableForTrees,cityCode,cityCodes);
            execAVLBenchmark(directory,50000,tableForTrees,cityCode,cityCodes);
            execAVLBenchmark(directory,100000,tableForTrees,cityCode,cityCodes);
            execAVLBenchmark(directory,500000,tableForTrees,cityCode,cityCodes);
            execAVLBenchmark(directory,1000000,tableForTrees,cityCode,cityCodes);

            execBTreeBenchmark(20,directory,10000,tableForTrees,cityCode,cityCodes);
            execBTreeBenchmark(20,directory,50000,tableForTrees,cityCode,cityCodes);
            execBTreeBenchmark(20,directory,100000,tableForTrees,cityCode,cityCodes);
            execBTreeBenchmark(20,directory,500000,tableForTrees,cityCode,cityCodes);
            execBTreeBenchmark(20,directory,1000000,tableForTrees,cityCode,cityCodes);

            execBTreeBenchmark(200,directory,10000,tableForTrees,cityCode,cityCodes);
            execBTreeBenchmark(200,directory,50000,tableForTrees,cityCode,cityCodes);
            execBTreeBenchmark(200,directory,100000,tableForTrees,cityCode,cityCodes);
            execBTreeBenchmark(200,directory,500000,tableForTrees,cityCode,cityCodes);
            execBTreeBenchmark(200,directory,1000000,tableForTrees,cityCode,cityCodes);

            cout << "Encerrando execução..." << endl;
        }
        else
        {
            cout << "Modo Inválido" << endl
                 << "Encerrando execução..." << endl;
        }
    }
    return 0;
}