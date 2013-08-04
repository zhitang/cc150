#include <iostream>
using namespace std;

void reverse(char * str) {
  char * end = str;
  char tmp;
  if(str) {
    while (*end) ++end;
  }
  end--;
  while (str < end) {
    tmp = *str;
    *str = *end;
    *end = tmp;
    str++; end--;
  }
}

int main(int argc, char * argv []) {
  char str[] = "this is a test string!";
  cout << "orignal string: " << str << endl;
  reverse(str);
  cout << "reversed string: " << str << endl;
  return 1;
}
