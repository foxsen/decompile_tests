#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v[10];
    for (int i = 0; i < n; ++i) {
      int x = s[i] - '0';
      v[x].push_back(i);
    }
    int ans[n];
    int mn1 = -1;
    int mn2 = -1;
    int m1 = 0;
    int m2 = 0;
    bool ok1 = true;
    bool ok = true;
    for (int i = 0; i < 10; ++i) {
      if (v[i].size() != 0) {
        for (const auto& x : v[i]) {
          if (x > mn1 && ok1) {
            ans[x] = 1;
            mn1 = max(mn1, x);
            m1 = max(m1, i);
          } else if (x > mn1 && i <= m2) {
            ans[x] = 1;
            mn1 = max(mn1, x);
            m1 = max(m1, i);
          } else if (x > mn2) {
            ok1 = false;
            ans[x] = 2;
            mn2 = max(mn2, x);
            if (m2 == 0) m2 = i;
          } else {
            ok = false;
            break;
          }
        }
        if (!ok) break;
      }
    }
    if (!ok)
      cout << "-" << '\n';
    else {
      for (int i = 0; i < n; ++i) {
        cout << ans[i];
      }
      cout << '\n';
    }
  }
}
