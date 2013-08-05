#include <iostream>
#include <string>

using namespace std;

int setChar(char * a, char c, int & index, int count) {
  a[index++] = c;
  string cc = to_string(count);
  for (int i = 0; i < cc.length(); i++) {
    a[index++] = cc[i];
  }
  return index;
}

int countCompression(string & s) {
  if (s.length() == 0) return 0;
  char c = s[0];
  int size = 0;
  int count = 1;
  for(int i = 1; i < s.length(); i++) {
    if (s[i] == c) count++;
    else {
      c = s[i];
      size += 1 + (to_string(count)).length();
      count = 1;
    }
  }
  size += 1 + (to_string(count)).length();
  return size;
}

string compressString(string & s) {
  int newSize = countCompression(s);
  if (s.length() <= newSize) return s;
  char * compressedArray = new char[newSize];
  int index = 0;
  char c = s[0];
  int count = 1;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == c) count++;
    else {
      c = s[i];
      index = setChar(compressedArray, c, index, count);
      count = 1;
    }
  }
  index = setChar(compressedArray, c, index, count);
  string cstr(compressedArray);
  delete [] compressedArray;
  return cstr;
}


int main(int argc, char * argv[]) {
  string str("aabbccccccccccccccc");
  //cout << countCompression(str) << endl;
  cout << compressString(str) << endl;
  
  return 1;
}
