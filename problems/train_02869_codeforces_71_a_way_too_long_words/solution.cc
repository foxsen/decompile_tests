#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  while (cin >> s) {
    if (s.length() < 11)
      cout << s << endl;
    else
      cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;
  }
}
