#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Util.h"
#include "LinkedList.h"

class HashTable {
  public:
    /**
    * Constructs a new hash table.
    * @param size The number of buckets with which the table should be initialized.
    **/
    HashTable(int size);

    /**
    * Inserts the element x into the table.
    * @param x The value to insert.
    * @returns A value indicating whether the insertion was successful.
    **/
    bool insertElement(int x);

    /**
    * Deletes an element from the table.
    * @param x The value to delete.
    * @returns A value indicating whether the deletion was successful.
    **/
    bool deleteElement(int x);

    /**
    * Finds an element in the table.
    * @param x The value to find.
    * @returns The index in the table that holds x, or -1 if the element is not in the table.
    **/
    int find(int x);

    /**
    * Prints the hash table.
    **/
    void print();

    /**
    * Called when the hash table is destroyed.
    **/
    ~HashTable();
  private:
    void rehash();
    int hash(int x);
    void initializeTable(int size);
    LinkedList** table;
    int size;
    int elements;
};

#endif
