#include <bits/stdc++.h>
#pragma GCC optimize( \
    "Ofast,no-stack-protector,unroll-loops,no-stack-protector,fast-math")
using namespace std;
const int N = 2e5 + 5, M = 2 * N + 5;
int n;
char s[N];
int solve(int l, int r, int lev, bool state) {
  if (l > r) return 0;
  if (l == r || state == false) {
    int ret = 0;
    for (int j = l; j <= r; ++j) ret += (s[j] - 'a' != lev);
    return ret;
  }
  int ret = n + 5;
  int mid = (l + r) / 2;
  ret = min(ret, solve(l, mid, lev, false) + solve(mid + 1, r, lev + 1, true));
  ret = min(ret, solve(l, mid, lev + 1, true) + solve(mid + 1, r, lev, false));
  return ret;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %s", &n, s);
    printf("%d\n", solve(0, n - 1, 0, true));
  }
}
