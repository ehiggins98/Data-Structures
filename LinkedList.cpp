#include "LinkedList.h"

LinkedList::~LinkedList() {
  Node* current = _front;
  while (current != nullptr) {
    Node* temp = current;
    current = current->getNext();
    delete temp;
  }
}

bool LinkedList::isEmpty() {
  return _front == nullptr;
}

void LinkedList::insertElement(int x) {
  Node* newNode = new Node(x);

  if (_front == nullptr) {
    _front = newNode;
  }
  else {
    newNode->setNext(_front);
    _front = newNode;
  }
}

void LinkedList::deleteElement(int x) throw (std::invalid_argument) {
  if (_front == nullptr)
    throw std::invalid_argument("list is empty");

  if (_front->getValue() == x) {
    Node* temp = _front;
    _front = _front->getNext();

    delete temp;
    return;
  }

  for (Node* current = _front; current->getNext() != nullptr; current = current->getNext()) {
    if (current->getNext()->getValue() == x) {
      Node* temp = current->getNext();
      current->setNext(current->getNext()->getNext());
      delete temp;
      return;
    }
  }

  throw std::invalid_argument("x is not in list");
}

bool LinkedList::contains(int x) {
  for (Node* current = _front; current != nullptr; current = current->getNext()) {
    if (current->getValue() == x) {
      return true;
    }
  }

  return false;
}

void LinkedList::print() {
  for (Node* current = _front; current != nullptr; current = current->getNext()) {
    std::cout<<"-> "<<current->getValue()<<" ";
  }

  std::cout<<std::endl;
}

Node* LinkedList::getFront() {
  return _front;
}
