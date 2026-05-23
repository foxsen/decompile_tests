#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      cout << "YES" << endl;
      cout << s.substr(i - 1, 2);
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
