#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "listnode.h"
using namespace std;

template <typename T>
class List {
 public:
  List();
  ~List();
  void insertNewNode(T);
  void print();
  Node<T> * search(T);

 private:
  Node<T> * head;
  Node<T> * tail;
  bool isEmpty();
  void insertAtFront(T);
  void insertAtEnd(T);
};

template<typename T>
List<T>::List() {
  head = nullptr;
  tail = nullptr;
}

template<typename T>
List<T>::~List() {
  if (!isEmpty()) {
    Node<T> * current = head;
    Node<T> * temp;

    while (current != 0) {
      temp = current;
      current = current->next;
      delete temp;
    }
  }
}

template<typename T>
bool List<T>::isEmpty() {
  if (head == nullptr && tail == nullptr)
    return true;
  else 
    return false;
}

template<typename T>
void List<T>::print() {
  if(isEmpty()) {
    cout << "The list is empty." << endl;
  } else {
    Node<T> * current = head;
    cout << "The contents of the list is: ";
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
}

template<typename T>
void List<T>::insertAtFront(T dataIn) {
  if (isEmpty()) {
    Node<T> * newNode = new Node<T>(dataIn);
    head = newNode;
    tail = newNode;
  } else {
    Node<T> * newNode = new Node<T>(dataIn);
    newNode->next = head;
    head = newNode;
  }
}

template<typename T>
void List<T>::insertAtEnd(T dataIn) {
  if (isEmpty()) {
    Node<T> * newNode = new Node<T>(dataIn);
    head = newNode;
    tail = newNode;
  } else {
    Node<T> * newNode = new Node<T>(dataIn);
    tail->next = newNode;
    tail = newNode;
  }
}

template<typename T>
Node<T> * List<T>::search (T key) {
  Node<T> * node;
  bool found = false;

  node = head;
  while ((!found) && (node != nullptr)) {
    if (node->data == key) found = true;
    else node = node->next;
  }
  return node;
}

template<typename T>
void List<T>::insertNewNode (T dataIn) {
  if (isEmpty()) insertAtFront(dataIn);
  else {
    if (dataIn < head->data) insertAtFront(dataIn);
    else if (dataIn >= tail->data) insertAtEnd(dataIn);
    else {
      Node<T> * current = head;
      Node<T> * newNode = new Node<T>(dataIn);
      while (current != tail) {
	if ((newNode->data < current->next->data) && (newNode->data >= current->data)) {
	  Node<T> * tmp = current->next;
	  current->next = newNode;
	  newNode->next = tmp;
	  break;
	}
	current = current->next;
      }
    }
  }
}
#endif
