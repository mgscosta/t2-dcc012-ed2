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

   vector<string> teste;
  while (menu == true)
  {
    cout << "Digite a opção" << endl;
    cout << "[1] - Etapa 2" << endl;
    cout << teste[0] << endl;
    switch (option)
    {
    case 1:
      aux = reader.readPreProcessedCovidDataFromFile("brazil_covid19_cities_processado.csv");
      for(int i =0; i < hashTable.getItemVector().size(); i++) {
             hashTable.insert(*(aux[i]));
      }
      menu = false;
      break;

    default:
      cout << "Opção inválida, digite novamente" << endl;
      break;
    }
  }
}