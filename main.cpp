#include <iostream>
#include "Hash.h"
#include "DataReader.h"
#include "HashItem.h"

using namespace std;

int main()
{
  bool menu = true;
  int option;
  DataReader reader;
  Hash hashTable;
  vector <HashItem*> aux;
 
  while (menu == true)
  {
    cout << "Digite a opção" << endl;
    cout << "[1] - Etapa 2" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        aux = reader.readPreProcessedCovidDataFromFile("brazil_covid19_cities_processado.csv");
      // for(int i =0; i < hashTable.getItemVector().size(); i++) {
      //         hashTable.insert(aux[i]);
      // }
       // Início Teste ----------
      cout << "KEY: " << aux[0]->getKey() << "VALUE: "<< aux[0]->getValue().getData() << endl;
      hashTable.insert(aux[0]);
   //   cout << "AFTERINSERT KEY: " << hashTable.getItemVector()[876]->getKey() << "VALUE: "<< hashTable.getItemVector()[876]->getValue().getData() << endl;
      hashTable.insert(aux[24]);
      hashTable.print();
      cout << hashTable.search(aux[0]->getKey()) << endl;;
      cout << hashTable.search(aux[24]->getKey()) << endl;
       // Fim Teste    ----------
      menu = false;
      break;

    default:
      cout << "Opção inválida, digite novamente" << endl;
      break;
    }
  }
}