#include <bits/stdc++.h>
using namespace std;
long long n, m, k, p[1005], siz[1005], st[1005];
long long get(long long x) {
  if (x == p[x]) return x;
  p[x] = get(p[x]);
  return p[x];
}
void unite(long long x, long long y) {
  x = get(x);
  y = get(y);
  if (x == y) return;
  if (st[x]) swap(x, y);
  p[x] = y;
  siz[y] += siz[x];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    p[i] = i;
    siz[i] = 1;
  }
  for (long long i = 0; i < k; i++) {
    long long y;
    cin >> y;
    y--;
    st[y] = 1;
  }
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    unite(u, v);
  }
  long long Max = -1;
  for (long long i = 0; i < n; i++) {
    if (st[i] == 1 && (Max == -1 || siz[i] > siz[Max])) Max = i;
  }
  for (long long i = 0; i < n; i++)
    if (st[get(i)] == 0) unite(i, Max);
  long long ans = 0;
  for (long long i = 0; i < n; i++)
    if (st[i]) {
      ans += siz[i] * (siz[i] - 1) / 2;
    }
  ans -= m;
  cout << ans;
}
