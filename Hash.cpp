#include "Hash.h"

Hash::Hash()
{
  this->size = CAPACITY;
  this->count = 0;
  items.resize(this->size);
  for (int i = 0; i < this->size; i++)
  {
    this->items[i] = NULL;
    this->items[i]->setNext(-2);
  }
}

Hash::~Hash() {}

unsigned long Hash::hash(string key)
{
  unsigned long i = 0;
  for (int j = 0; key[j]; j++)
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
    this->items[index]->setNext(-1);
    incrementCount();
  }
  else
  {
    handleColision(item, index);
  }
}

string Hash::search(string key)
{
  unsigned long index = hash(key);
  long next;
  HashItem *item = this->items[index];

  if (item != NULL)
  {
    if (item->getKey() == key)
    {
      return key;
    }
    else
    {
      if(item->getNext() != -1 && item->getNext() != -2) {
      next = item->getNext();
      item = this->items[next];
      return item->getKey();
      }
      else {
        return NULL;
      }
    }
  }
  else
  {
    return NULL;
  }
}

void Hash::print()
{
  cout << "Tabela Hash" << endl;
  cout << "-------------------" << endl;
  for (int i = 0; i < this->items.size(); i++)
  {
    if (this->items[i] != NULL)
    {
      cout << "Index: " << i << "Key: " << this->items[i]->getKey() << "Value: " << this->items[i]->getValue().getData() << endl;
    }
  }
  cout << "-------------------" << endl;
}

void Hash::handleColision(HashItem *item, int index)
{
  cout << "Handling colision..." << endl;
  unsigned long i = index + 1;

  while (this->items[i] == NULL)
  {
    i++;
  }
  this->items[index]->setNext(i);
  this->items[i] = item;
  this->items[i]->setNext(-1);
}

vector<HashItem *> Hash::getItemVector()
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