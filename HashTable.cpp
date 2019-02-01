#include "HashTable.h"

HashTable::HashTable(int size) {
  table = new LinkedList*[size];
  this->size = size;
  elements = 0;
  initializeTable(size);
}

bool HashTable::insertElement(int x) {
  int index = hash(x);
  if (table[index]->contains(x)) {
    std::cout<<x<<" is a duplicate of "<<x<<", can't be added to the hash table"<<std::endl;
    return false;
  }

  table[index]->insertElement(x);
  elements++;

  if (elements > size) {
    rehash();
    std::cout<<"hash table is rehashed"<<std::endl;
  }
  else {
    std::cout<<x<<" is added to the hash table"<<std::endl;
  }

  return true;
}

bool HashTable::deleteElement(int x) {
  int index = hash(x);
  try {
    table[index]->deleteElement(x);
    elements--;
    return true;
  }
  catch (std::exception& ex) {
    return false;
  }
}

int HashTable::find(int x) {
  int index = hash(x);
  return table[index]->contains(x) ? index : -1;
}

void HashTable::print() {
  for (int i = 0; i < size; i++) {
    std::cout<<i<<":";
    table[i]->print();
  }
}

HashTable::~HashTable() {
  for (int i = 0; i < size; i++) {
    delete table[i];
  }

  delete[] table;
}

void HashTable::rehash() {
  int newSize = 2 * size;
  for ( ; !prime(newSize); newSize++) {}

  LinkedList** newTable = new LinkedList*[newSize];

  int tempSize = size;
  LinkedList** tempTable = table;

  table = newTable;
  size = newSize;

  initializeTable(newSize);

  for (int i = 0; i < tempSize; i++) {
    for (Node* current = tempTable[i]->getFront(); current != nullptr; current = current->getNext()) {
      this->insertElement(current->getValue());
    }
  }

  for (int i = 0; i < tempSize; i++) {
    delete tempTable[i];
  }

  delete[] tempTable;
}

int HashTable::hash(int x) {
  return x % size;
}

void HashTable::initializeTable(int size) {
  for (int i = 0; i < size; i++) {
    table[i] = new LinkedList();
  }
}
