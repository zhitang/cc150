#include <iostream>
#include <string>

using namespace std;
const int ARRAY_SIZE = 256;

void replaceSpaces(char * str, int length) {
  int numSpaces = 0;
  for (int i = 0; i < length; i++) {
    if (str[i] == ' ') numSpaces++;
  }
  int newLength = length + 2 * numSpaces;
  str[newLength] = '\0';
  for (int i = length - 1; i >= 0; i--) {
    if (str[i] == ' ') {
      str[newLength - 1] = '0';
      str[newLength - 2] = '2';
      str[newLength - 3] = '%';
      newLength -= 3;
    } else {
      str[newLength - 1] = str[i];
      newLength--;
    }
  }
}

int main(int argc, char * argv[] ) {
  char * str = new char[ARRAY_SIZE];
  string test_str("this is a test string.");
  int realLength = test_str.length();

  test_str.copy(str, realLength);
  str[ARRAY_SIZE-1] = '\0'; 
  cout << str << endl;
  replaceSpaces(str, realLength);
  cout << str << endl;
  delete [] str;

}
