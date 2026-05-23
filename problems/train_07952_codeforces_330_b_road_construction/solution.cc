#include <bits/stdc++.h>
using namespace std;
const int N = 1007;
pair<int, int> p[N];
int deg[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    p[i].first = a, p[i].second = b;
    ++deg[a], ++deg[b];
  }
  cout << n - 1 << '\n';
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 0) {
      for (int j = 1; j <= n; ++j)
        if (j != i) cout << i << ' ' << j << '\n';
      return 0;
    }
  for (int i = 0; i < m - 1; ++i) {
    cout << p[i].first << ' ' << p[i + 1].first << '\n'
         << p[i].second << ' ' << p[i + 1].second << '\n';
  }
  cout << p[0].first << ' ' << p[1].second << '\n';
  return 0;
}
