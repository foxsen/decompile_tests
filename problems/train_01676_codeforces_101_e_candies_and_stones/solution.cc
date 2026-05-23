#include <bits/stdc++.h>
using namespace std;
int n, m;
int k;
bool debug = false;
int x[20005], y[20005], p, f[20005], g[20005];
string s;
int cal(int i, int j) { return (x[i] + y[j]) % p; }
int dd(int d, int l, int u, int r) {
  int mid = (d + u) / 2;
  int ans = 0;
  if (d == u) {
    ans += cal(d, l);
    for (int i = l + 1; i <= r; i++) {
      ans += cal(d, i);
      s += 'S';
    }
    return ans;
  }
  memset(f, 0, sizeof f);
  memset(g, 0, sizeof g);
  for (int i = d; i <= mid; i++) {
    for (int j = l; j <= r; j++) {
      f[j] = max(f[j], f[j - 1]) + cal(i, j);
    }
  }
  for (int i = u; i >= mid + 1; i--) {
    for (int j = r; j >= 1; j--) {
      g[j] = max(g[j], g[j + 1]) + cal(i, j);
    }
  }
  int mm = -1, tar;
  for (int i = l; i <= r; i++) {
    if (mm < f[i] + g[i]) {
      mm = f[i] + g[i];
      tar = i;
    }
  }
  ans += dd(d, l, mid, tar);
  s += 'C';
  ans += dd(mid + 1, tar, u, r);
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; i++) scanf("%d", x + i);
  for (int i = 1; i <= m; i++) scanf("%d", y + i);
  printf("%d\n", dd(1, 1, n, m));
  puts(s.c_str());
  return 0;
}
