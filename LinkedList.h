#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

class LinkedList {
  public:

    /**
    * Gets a value indicating whether the list is empty.
    * @returns A value indicating whether the list is empty.
    **/
    bool isEmpty();

    /**
    * Inserts an element at the front of the list.
    * @param x The element to insert.
    **/
    void insertElement(int x);

    /**
    * Deletes an element from the list.
    * @param x The element to delete.
    * @throw std::invalid_argument If x is not in the list.
    **/
    void deleteElement(int x) throw (std::invalid_argument);

    /**
    * Gets a value indicating whether the given x is in the list.
    * @param x The element for which to search.
    * @returns A value indicating whether x is in the list.
    **/
    bool contains(int x);

    /**
    * Prints the list.
    **/
    void print();

    /**
    * Returns the element at the front of the list.
    **/
    Node* getFront();

    /**
    * Called when the list is destroyed.
    **/
    ~LinkedList();
  private:
    Node* _front;
};

#endif
