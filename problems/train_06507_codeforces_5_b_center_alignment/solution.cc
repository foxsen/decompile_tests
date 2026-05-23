#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> buff;
  string line;
  int n = 0, ml = 0, i, alt = 0;
  while (getline(cin, line)) {
    if (line.length() > ml) ml = line.length();
    buff.push_back(line);
    n++;
  }
  for (i = 0; i < ml + 2; i++) cout << "*";
  cout << endl;
  for (i = 0; i < n; i++) {
    cout << "*";
    int bs = (ml - buff[i].length() + alt) / 2;
    int es = ml - buff[i].length() - bs;
    if ((ml - buff[i].length()) % 2 == 1) alt = 1 - alt;
    while (bs--) cout << " ";
    cout << buff[i];
    while (es--) cout << " ";
    cout << "*" << endl;
  }
  for (i = 0; i < ml + 2; i++) cout << "*";
  cout << endl;
}
