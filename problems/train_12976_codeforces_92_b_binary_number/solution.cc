#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int z = 0, on = 0, fl = 0;
  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] == '0' && fl == 1) {
      z++;
    } else if (str[i] == '1') {
      on++;
      fl = 1;
    }
  }
  if (on > 1) {
    cout << str.size() + 1 + z << endl;
  } else if (on == 1) {
    cout << str.size() - 1 << endl;
  }
  return 0;
}
