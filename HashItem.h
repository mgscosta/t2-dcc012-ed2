#ifndef HASHITEM_H
#define HASHITEM_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "CovidData.h"

using namespace std;

class HashItem
{
private:
   string key;      // chave (par código da cidade, data)
   CovidData value; // valor covid data (data, iniciais do estado, nome da cidade, código da cidade, numero de casos, numero de mortes)
   long next;       // next pode armazenar três valores diferentes:
                    // -1 se já possui elemento no indice porém sem colisão prévia
                    // -2 se está o espaço está vazio
                    // qualquer valor positivo no range da tabela (até 1431490) que corresponde ao novo índice do valor que sofreu colisão

public:
   /**
     * Constructor
     * */
   HashItem(string key, CovidData value);

   /**
     * Destructor
     * */
   ~HashItem();

   /**
   * Getter & Setter Key
   * */
   string getKey();
   void setKey(string new_key);

   /**
   * Getter & Setter Value
   * */
   CovidData getValue();
   void setValue(CovidData new_value);

   /**
 * Getter & Setter next
 */
   long getNext();

   void setNext(long next);
};

#endif