#include <bits/stdc++.h>
using namespace std;
int n, u, r;
int a[80], b[80], k[80], p[80];
long long ans = 0x8000000000000000LL;
long long calc() {
  long long res = 0;
  for (int i = 1; i <= n; i++) res += a[i] * k[i];
  return res;
}
void dfs(int last, int dep) {
  if (((u - dep) & 1) == 0) ans = max(ans, calc());
  if (dep == u) return;
  int temp[31];
  if (last != 1) {
    for (int i = 1; i <= n; i++) a[i] ^= b[i];
    dfs(1, dep + 1);
    for (int i = 1; i <= n; i++) a[i] ^= b[i];
  }
  for (int i = 1; i <= n; i++) temp[i] = a[i];
  for (int i = 1; i <= n; i++) a[i] = temp[p[i]] + r;
  dfs(2, dep + 1);
  for (int i = 1; i <= n; i++) a[i] = temp[i];
}
int main() {
  scanf("%d%d%d", &n, &u, &r);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  dfs(0, 0);
  cout << ans << endl;
  return 0;
}
