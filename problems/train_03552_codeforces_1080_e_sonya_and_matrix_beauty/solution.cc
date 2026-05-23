#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * f;
}
template <typename T>
inline bool Max(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool Min(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const int N = 254;
const unsigned long long mod = 1e13 + 7;
int n, m;
int cnt[27], g[N][N][N];
long long ans;
char s[N];
unsigned long long v[N][N], f[N][N][N], pre[N], suf[N], val[N], sg[N], bin[N];
int idx(char c) { return c - 'a'; }
unsigned long long Rand() {
  static unsigned long long seed = 703;
  return seed = seed * 48271 % mod;
}
unsigned long long v1(int l, int r) {
  if (l > r) return 0;
  return pre[r] - pre[l - 1] * bin[r - l + 1];
}
unsigned long long v2(int l, int r) {
  if (l > r) return 0;
  return suf[l] - suf[r + 1] * bin[r - l + 1];
}
int main() {
  n = gi(), m = gi();
  for (int i = 0; i <= 25; ++i) val[i] = Rand();
  bin[0] = 1;
  for (int i = 1; i <= 250; ++i) bin[i] = bin[i - 1] * 233;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; ++j) v[i][j] = idx(s[j]);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      memset(cnt, 0, sizeof cnt);
      int c1 = 0;
      unsigned long long hv = 0;
      for (int k = j; k <= m; ++k) {
        if (++cnt[v[i][k]] & 1)
          ++c1;
        else
          --c1;
        hv = hv ^ ((cnt[v[i][k]] - 1) * val[v[i][k]]) ^
             (cnt[v[i][k]] * val[v[i][k]]);
        f[i][j][k] = hv;
        if (k - j + 1 & 1) {
          if (c1 == 1) g[i][j][k] = 1;
        } else if (c1 == 0)
          g[i][j][k] = 1;
      }
    }
  for (int j = 1; j <= m; ++j)
    for (int k = j; k <= m; ++k) {
      for (int i = 1; i <= n; ++i)
        sg[i] = sg[i - 1] + g[i][j][k], pre[i] = pre[i - 1] * 233 + f[i][j][k];
      for (int i = n; i; --i) suf[i] = suf[i + 1] * 233 + f[i][j][k];
      for (int i = 1; i <= n; ++i)
        if (g[i][j][k]) {
          int l = 0, r = min(i - 1, n - i);
          while (l < r) {
            int mid = l + r + 1 >> 1;
            if (v1(i - mid, i - 1) == v2(i + 1, i + mid) &&
                sg[i - 1] - sg[i - mid - 1] == mid &&
                sg[i + mid] - sg[i] == mid)
              l = mid;
            else
              r = mid - 1;
          }
          ans += l + 1;
          if (i == n || f[i][j][k] != f[i + 1][j][k] || !g[i + 1][j][k])
            continue;
          l = 0, r = min(i - 1, n - i - 1);
          while (l < r) {
            int mid = l + r + 1 >> 1;
            if (v1(i - mid, i - 1) == v2(i + 2, i + mid + 1) &&
                sg[i - 1] - sg[i - mid - 1] == mid &&
                sg[i + mid + 1] - sg[i + 1] == mid)
              l = mid;
            else
              r = mid - 1;
          }
          ans += l + 1;
        }
    }
  printf("%I64d\n", ans);
  return 0;
}
