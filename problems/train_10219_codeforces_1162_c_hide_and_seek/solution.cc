#include <bits/stdc++.h>
using namespace std;
int mn[100005], mx[100005];
int n, k;
int q[100005];
bool func(int x, int y) {
  if (mn[x] < mx[y]) return true;
  return false;
}
int main() {
  scanf("%d%d", &n, &k);
  int i;
  for (i = 1; i <= n; i++) {
    mn[i] = 100000000;
    mx[i] = -100000000;
  }
  for (i = 0; i < k; i++) {
    scanf("%d", &q[i]);
    mn[q[i]] = min(mn[q[i]], i);
    mx[q[i]] = max(mx[q[i]], i);
  }
  int ans = 3 * n - 2;
  if (n == 1) ans = 1;
  for (i = 1; i <= n; i++) {
    if (mn[i] != 100000000) ans--;
    if (i > 1) ans -= func(i, i - 1);
    if (i < n) ans -= func(i, i + 1);
  }
  printf("%d", ans);
  return 0;
}
