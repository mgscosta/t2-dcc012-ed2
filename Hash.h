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
     * Função hash djb32 que utiliza as constantes 5381 e 33 para geração de índices na tabela hash.
     * Possui uma boa distribuição de chaves e velocidade satisfatória. Utiliza-se o % (mod) para limitar os índices entre o
     * range da tabela (max = CAPACITY).
     * */
  unsigned long hash(string key);

  /**
     * Insere item [chave, valor (Covid Data) e next (ponteiro para o índice onde o item foi rearranjado ou flag)] na tabela Hash
     * */
  void insert(HashItem * item);

  /**
     * Busca um valor na tabela Hash usando sua chave e o retorna caso o encontre, retornando null em caso negativo.
     * */
  string search(string key);


 /**
  * Trata colisão utilizando o método de encadeamento coalescido (sem porão). 
  */
 void handleColision(HashItem* item, int index);
  
  /**
   * Printa tabela Hash, possuindo a opção de imprimir em arquivo ou em console
   * 
   * @param bool archive
   * @param string [filename]
   * */
  void print(bool archive,string filename = "");
  /**
   * Getters e Setters Item
   * */

  vector<HashItem*> getItemVector();
  void setItemVector(vector<HashItem*> v_i);

   /**
    * Get Size
    */
   int getSize();
  /**
   * Incrementa Contador
   * */
  void incrementCount();
};

#endif