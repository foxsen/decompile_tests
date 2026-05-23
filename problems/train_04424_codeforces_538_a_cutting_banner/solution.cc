#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  string s;
  string r = "CODEFORCES";
  cin >> s;
  bool ans = false;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      string t = s;
      t.erase(i, j - i + 1);
      if (t == r) ans = true;
    }
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
