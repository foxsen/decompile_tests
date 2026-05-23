#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[51], t;
  int tot, mint = 9999, w, n, z;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  z = s[1].size();
  for (int i = 1; i <= n; i++) {
    tot = 0;
    for (int j = 1; j <= n; j++) {
      t = s[j];
      w = 0;
      while (t != s[i]) {
        t = t + t[0];
        t.erase(0, 1);
        tot++;
        if (++w > z) {
          cout << -1;
          return 0;
        }
      }
    }
    if (tot < mint) mint = tot;
  }
  cout << mint;
}
