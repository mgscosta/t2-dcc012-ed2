#include "HashItem.h"


HashItem::HashItem(string key, CovidData value){
  this->key = key;
  this->value = value;
  this->next = -2;
}

// Override
// HashItem::HashItem(){}

HashItem::~HashItem(){}


string HashItem::getKey() {
  return this->key;
}


void HashItem::setKey(string new_key) {
  this->key = new_key;
}

  CovidData HashItem::getValue() {
  return this->value;
}

void HashItem::setValue(CovidData new_value) {
  this->value = new_value;
}

 long HashItem::getNext(){
    return this->next;
  }

  void HashItem::setNext(long next) {
    this->next = next;
  } 