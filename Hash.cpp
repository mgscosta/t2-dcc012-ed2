#include "Hash.h"

Hash::Hash()
{
  this->size = CAPACITY;
  this->count = 0;
  items.resize(this->size);
  for(int i =0; i < size; i++) {
    this->items[i] = NULL;
  }
}

Hash::~Hash() {}

unsigned long Hash::hash(string key)
{
  unsigned long hash = 5381;

  for (int i = 0; i < key.size(); i++)
  {
    hash = ((hash << 5) + hash) + key[i];
  }

  return hash;
}

void Hash::insert(HashItem * item)
{
  unsigned long index = hash((*item).getKey());
  
 if(this->items[index] == NULL ) { // caso onde não existe dados na posição
  if(this->count == this-> size) {
    cout << "Tabela cheia" << endl;
    return;
 }
  this->items[index] = item;
        incrementCount();
    }
    else {
      if(this->items[index] == item ) // se o item é igual (key e valor){
        return;
      }
      else {
        cout << "oi" << endl;
        handleColision(this->items, index);
      }
    }  
  
}

vector<HashItem*> Hash::getItemVector()
{
  return this->items;
}

void Hash::setItemVector(vector<HashItem*> v_i)
{
  this->items = v_i;
}

void Hash::incrementCount()
{
  this->count++;
}