#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
int a[MAXN], l[MAXN], r[MAXN];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  l[1] = 1;
  for (int i = 2; i <= n; i++) {
    l[i] = (a[i] >= a[i - 1] ? l[i - 1] + 1 : 1);
  }
  r[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    r[i] = (a[i] >= a[i + 1] ? r[i + 1] + 1 : 1);
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, l[i] + r[i] - 1);
  }
  printf("%d\n", ans);
}
int main() {
  solve();
  return 0;
}
