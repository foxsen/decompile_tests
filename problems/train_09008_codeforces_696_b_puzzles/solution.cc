#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, x, y, si[N];
double ans[N];
int tot, fi[N], a[N], ne[N];
inline void add(int x, int y) {
  a[++tot] = y;
  ne[tot] = fi[x];
  fi[x] = tot;
}
inline void pre(int x) {
  si[x] = 1;
  for (int i = fi[x]; i; i = ne[i]) pre(a[i]), si[x] += si[a[i]];
}
inline void dfs(int x) {
  for (int i = fi[x]; i; i = ne[i]) {
    ans[a[i]] = ans[x] + 1 + (si[x] - si[a[i]] - 1) * 0.5;
    dfs(a[i]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) scanf("%d", &x), add(x, i);
  pre(1);
  ans[1] = 1;
  dfs(1);
  for (int i = 1; i <= n; ++i) printf("%.10lf ", ans[i]);
  return 0;
}
