#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int nex[maxn], par[maxn], siz[maxn];
int find_par(int x) {
  if (par[x] != x) par[x] = find_par(par[x]);
  return par[x];
}
void merge(int x, int y) {
  x = find_par(x);
  y = find_par(y);
  if (siz[y] < siz[x]) swap(x, y);
  par[x] = y;
  siz[y] += siz[x];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    par[i] = i;
    nex[i] = i + 1;
    siz[i] = 1;
  }
  int t, x, y;
  for (int i = 0; i < q; i++) {
    cin >> t >> x >> y;
    x--;
    y--;
    if (t == 1)
      merge(x, y);
    else if (t == 2) {
      int xp;
      while (x < y) {
        merge(x, y);
        xp = x;
        x = nex[x];
        nex[xp] = nex[y];
      }
    } else {
      if (find_par(x) == find_par(y))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
