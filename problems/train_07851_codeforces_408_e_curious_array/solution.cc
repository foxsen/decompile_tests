#include <bits/stdc++.h>
using namespace std;
int a[100000 + 1];
int comb[100000 + 100 + 1][100 + 1], ans[100000 + 2][100 + 2];
template <typename T1, typename T2>
void madd(T1& x, const T2& y) {
  (x += y) >= 1000000007 && (x -= 1000000007);
}
template <typename T1, typename T2, typename T3>
void madd(T1& x, const T2& y, const T3& z) {
  (x += y) >= 1000000007 && (x -= 1000000007);
  (x += z) >= 1000000007 && (x -= 1000000007);
}
template <typename T1, typename T2>
T1 mplus(const T1& x, const T2& y) {
  T1 ret = x + y;
  return ret >= 1000000007 ? ret - 1000000007 : ret;
}
int main() {
  comb[0][0] = 1;
  for (int i = 1, maxn = 100000 + 100 + 1, maxm = 100 + 1; i < maxn; ++i) {
    comb[i][0] = 1;
    for (int j = 1; j <= i && j < maxm; ++j)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 1000000007;
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; ++i <= n; scanf("%d", a + i))
    ;
  int l, r, k;
  for (++m; --m;) {
    scanf("%d%d%d", &l, &r, &k);
    for (int i = -1; ++i <= k; madd(ans[l][i], comb[k][k - i]))
      ;
    for (int i = -1; ++i <= k;
         madd(ans[r + 1][i], 1000000007 - comb[k + r - l + 1][k - i]))
      ;
  }
  for (int i = 0; ++i <= n;)
    for (int j = 100 + 2; --j;
         madd(ans[i + 1][j - 1], ans[i][j], ans[i][j - 1]))
      ;
  for (int i = 0; ++i <= n; printf("%d ", mplus(ans[i][0], a[i])))
    ;
  return 0;
}
