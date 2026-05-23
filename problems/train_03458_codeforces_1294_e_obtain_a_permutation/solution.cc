#include <bits/stdc++.h>
using namespace std;
int n, m, rs, d[200010], c[200010];
vector<int> a[200010];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    a[i].push_back(0);
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      int val = (i - 1) * m + j;
      c[val] = i;
    }
    int s = n;
    for (int i = 1; i <= n; i++) {
      if (c[a[i][j]]) {
        d[(i - c[a[i][j]] + n) % n]++;
      }
    }
    for (int i = 0; i < n; i++) {
      s = min(s, n - d[i] + i);
      d[i] = 0;
    }
    rs += s;
    for (int i = 1; i <= n; i++) {
      int val = (i - 1) * m + j;
      c[val] = 0;
    }
  }
  cout << rs;
  return 0;
}
