#ifndef LISTNODE_H
#define LISTNODE_H
template <typename T>
class List;

template<typename T>
class Node {
  friend class List<T>;
 public:
  Node(T);
  T getData();
 private:
  T data;
  Node * next;
};

template<typename T>
Node<T>::Node(T dataIn) {
  data = dataIn;
  next = 0;
}

template<typename T>
T Node<T>::getData() {
  return data;
}

#endif
