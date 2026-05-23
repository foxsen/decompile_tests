#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int man[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      if (u > v)
        man[v]++;
      else if (u < v)
        man[u]++;
    }
    long long int ans = 0;
    for (int i = 1; i <= n; i++)
      if (man[i] == 0) ans++;
    int q;
    cin >> q;
    while (q--) {
      int u, v;
      int op;
      cin >> op;
      if (op == 1) {
        cin >> u >> v;
        if (u > v) {
          man[v]++;
          if (man[v] == 1) ans--;
        } else {
          man[u]++;
          if (man[u] == 1) ans--;
        }
      } else if (op == 2) {
        cin >> u >> v;
        if (u > v) {
          man[v]--;
          if (man[v] == 0) ans++;
        } else {
          man[u]--;
          if (man[u] == 0) ans++;
        }
      } else {
        cout << ans << "\n";
      }
    }
  }
  return 0;
}
