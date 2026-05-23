#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n;
  cin >> n;
  map<char, int> m;
  int c = 0;
  for (int i = 0; i < 26; i++) {
    m['a' + i] = 0;
  }
  for (int i = 0; i < s.length(); i++) {
    if (m[s[i]] == 0) {
      c++;
      m[s[i]] = 1;
    }
  }
  if (n > s.length()) {
    cout << "impossible";
  } else {
    n = n - c;
    if (n <= 0) {
      cout << 0;
      return 0;
    }
    int q = s.length() - c;
    if (q < n) {
      cout << "impossible";
    } else {
      cout << n;
    }
  }
}
