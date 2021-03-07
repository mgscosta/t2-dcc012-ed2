#include "Hash.h"

Hash::Hash()
{
  this->size = CAPACITY;
  this->count = 0;
  items.resize(this->size);
  for (int i = 0; i < this->size; i++)
  {
    this->items[i] = NULL;
  }
}

Hash::~Hash() {}

unsigned long Hash::hash(string key)
{
   unsigned long i = 0;
    for (int j=0; key[j]; j++)
        i += key[j];
    return i % CAPACITY;
}

void Hash::insert(HashItem *item)
{
  unsigned long index = hash(item->getKey());
  cout << "INSERINDO A CHAVE: " << item->getKey() << "NO INDEX: " << index << endl;

  if (this->items[index] == NULL)
  { // posição vazia
    if (this->count == this->size)
    {
      cout << "Tabela cheia" << endl;
      return;
    }
    this->items[index] = item;
    incrementCount();
  }
  // else
  // {
  //   handleColision(this->items, index);
  // }
}

string Hash::search(string key) {
  int index = hash(key);
  HashItem * item = this->items[index];
  if(item != NULL) {
    if(item->getKey() == key) {
      return key;
    }
  }
  return NULL;
}

void Hash::print() {
  cout << "Tabela Hash" << endl;
  cout << "-------------------" << endl;
  for(int i =0; i < this->items.size(); i++) {
    if(this->items[i] != NULL) {
      cout << "Index: " << i << "Key: " << this->items[i]->getKey() << "Value: " << this->items[i]->getValue().getData() << endl;
    }
  }
  cout << "-------------------" << endl;
}

void Hash::handleColision(int index) {
  cout << "Handling colision..." << endl;
}

vector<HashItem*> Hash::getItemVector()
{
  return this->items;
}

void Hash::setItemVector(vector<HashItem *> v_i)
{
  this->items = v_i;
}

void Hash::incrementCount()
{
  this->count++;
}