#include <iostream>
#include <string>
using namespace std;

bool hasAllUniqueChars(string s) {
  int mask = 0;
  for (int i = 0; i < s.length(); i++) {
    int val = s[i] - 'a';
    if (mask & (1 >> val) > 0) return false;
    else mask |= (1 >> val);
  }
  return true;
}

int main(int argc, char * argv []) {
  string testStrings [] = {"abcdefg12345",
			   "1    xyz",
			   "4367890-abc",
			   "afdljlfjadfjgdallgg"};
  for (int i = 0; i < sizeof(testStrings)/sizeof(string); i++) {
    cout << testStrings[i] << " has unique chars? ";
    cout << (hasAllUniqueChars(testStrings[i]) ? "true" : "false") << endl;
  }

}
