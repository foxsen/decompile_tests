#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 55;
int n, c, a, b = 10, d, l;
string s;
int main() {
  cin >> s;
  for (int i = s.length() - 2; i >= 0; i--) {
    a = int(s[i]) - 46;
    if (a % 2 == 0) {
      if (b == 10) b = i;
      if (s[i] < s[s.length() - 1]) b = i;
    }
    if (i == 0 && b == 10) {
      cout << -1;
      return 0;
    }
  }
  swap(s[b], s[s.length() - 1]);
  cout << s;
  return 0;
}
