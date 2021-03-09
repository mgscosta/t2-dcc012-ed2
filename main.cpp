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
      for(int i =0; i < aux.size(); /*test i < 15*/ i++) {
              hashTable.insert(aux[i]);
      }
       // Início Teste ----------
      // hashTable.print();
       // Fim Teste    ----------
      menu = false;
      break;

    default:
      cout << "Opção inválida, digite novamente" << endl;
      break;
    }
  }
}