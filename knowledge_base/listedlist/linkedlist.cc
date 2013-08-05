#include <iostream>
#include <ctime>

#include "listnode.h"
#include "list.h"

using namespace std;

int main() {
  const int size = 10;
  int a[size];
  srand(time(0));
  for (int i = 0; i < size; i++) {
    a[i] = rand() % 101;
    cout << a[i] << " ";
  }
  cout << endl;
  List<int> intList;
  for (int i = 0; i < size; i++) {
    intList.insertAtFront(a[i]);
  }
  intList.print();
  return 1;
}
