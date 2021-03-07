#ifndef HASH_H
#define HASH_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "HashItem.h"

#define CAPACITY 1431490 // nº de linhas do arquivo .csv

using namespace std;

class Hash
{
private:
  int size;
  int count;
  vector<HashItem*> items;

public:
  /**
     * Constructor
     * */
  Hash();

  /**
     * Destructor
     * */
  ~Hash();

  /**
     * Função hash
     * */
  unsigned long hash(string key);

  /**
     * Insere item na tabela Hash
     * */
  void insert(HashItem * item);

  /**
     * Busca um valor na tabela Hash usando sua chave e o retorna caso o encontre
     * */
  string search(string key);

  /**
 * Deleta um item da tabela Hash
 * */
  void del(HashItem item);

 /**
  * Trata colisão utilizando o método de encadeamento coalescido
  */
 void handleColision(HashItem* item, int index);
  
  /**
   * Printa tabela
   * */
  void print();
  /**
   * Getters e Setters Item
   * */

  vector<HashItem*> getItemVector();
  void setItemVector(vector<HashItem*> v_i);

  /**
   * Incrementa Contador
   * */
  void incrementCount();
};

#endif