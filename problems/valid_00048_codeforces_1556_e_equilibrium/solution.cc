#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int n, m, lg[maxn], pw[30];
long long a[maxn], b[maxn], chasum[maxn];
long long mn[maxn][30], mx[maxn][30];
long long qmx(int l, int r) {
  int len = r - l + 1;
  int k = lg[len];
  return max(mx[l][k], mx[r - pw[k] + 1][k]);
}
long long qmn(int l, int r) {
  int len = r - l + 1;
  int k = lg[len];
  return min(mn[l][k], mn[r - pw[k] + 1][k]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &b[i]);
  }
  pw[0] = 1;
  for (int i = 1; i <= 20; ++i) {
    pw[i] = pw[i - 1] * 2;
  }
  for (int i = 2; i <= n; ++i) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; i <= n; ++i) {
    chasum[i] = chasum[i - 1] + b[i] - a[i];
  }
  for (int j = 0; j <= 20; ++j) {
    for (int i = 1; i + pw[j] - 1 <= n; ++i) {
      if (j == 0)
        mx[i][j] = chasum[i];
      else
        mx[i][j] = max(mx[i][j - 1], mx[i + pw[j - 1]][j - 1]);
    }
  }
  for (int j = 0; j <= 20; ++j) {
    for (int i = 1; i + pw[j] - 1 <= n; ++i) {
      if (j == 0)
        mn[i][j] = chasum[i];
      else
        mn[i][j] = min(mn[i][j - 1], mn[i + pw[j - 1]][j - 1]);
    }
  }
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (chasum[r] == chasum[l - 1] && qmn(l, r) == chasum[l - 1]) {
      printf("%lld\n", qmx(l, r) - qmn(l, r));
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
