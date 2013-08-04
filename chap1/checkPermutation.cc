#include <iostream>
#include <string>

using namespace std;
const int CHARSET_SIZE = 256;

bool isPermutation(const string & s1, const string & s2) {
  if (s1.length() != s2.length()) return false;
  int * checkArray = new int[CHARSET_SIZE];
  for (int i = 0; i < s1.length(); i++) {
    checkArray[s1[i]]++;
  }
  for (int i = 0; i < s1.length(); i++) {
    if(--checkArray[s2[i]] < 0) return false;
  }
  delete checkArray;
  return true;
}

int main(int argc, char * argv []) {
  const string s1 = "deg";
  const string s2 = "god";
  cout << (isPermutation(s1, s2)) << endl;
}
