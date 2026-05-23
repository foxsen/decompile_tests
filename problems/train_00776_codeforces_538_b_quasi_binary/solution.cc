#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 * 1000 + 100;
int a, b, c, t[maxN];
string s;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) t[i] = s[i] - '0';
  for (int i = 0; i < s.size(); i++) a = max(a, (s[i] - '0'));
  cout << a << endl;
  for (int i = 0; i < s.size(); i++)
    while (t[i] > 0) {
      b = 0;
      for (int j = 0; j < s.size(); j++) {
        if (t[j] > 0)
          b = (b * 10) + 1;
        else
          b = (b * 10) + 0;
        t[j]--;
      }
      cout << b << " ";
    }
  cout << endl;
  return 0;
}
