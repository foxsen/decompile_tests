#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
bool done[N];
set<int> a[N];
int b[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int x = 0;
  int res = 0;
  for (int i = 1; i <= m; i++) {
    b[i] = i;
  }
  m--;
  for (int i = 1; i <= n; i++) {
    int y;
    cin >> y;
    a[y].insert(i);
    if (i > 1 && y != x) {
      res++;
    }
    x = y;
  }
  cout << res << endl;
  while (m-- > 0) {
    int y;
    cin >> x >> y;
    int ox = x;
    x = b[x];
    y = b[y];
    if (a[x].size() < a[y].size()) {
      b[ox] = y;
      swap(x, y);
    }
    for (auto z : a[y]) {
      if (a[x].find(z - 1) != a[x].end()) {
        res--;
      }
      if (a[x].find(z + 1) != a[x].end()) {
        res--;
      }
    }
    for (auto z : a[y]) {
      a[x].insert(z);
    }
    a[y].clear();
    cout << res << endl;
  }
  return 0;
}
