#include <bits/stdc++.h>
using namespace std;
int prime[10010], tp;
bool isp[10010];
int ish[10000001];
int num[1000010];
int yin[21], ty;
int fa[1000010];
int n;
void prime_cal() {
  memset(isp, 0, sizeof(isp));
  tp = 0;
  for (int i = 2; i < 10010; ++i) {
    if (!isp[i]) prime[tp++] = i;
    for (int j = 0; j < tp && i * prime[j] < 10010; ++j) {
      isp[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
void yin_cal(int num) {
  ty = 0;
  int limit = (int)sqrt((double)(num));
  for (int i = 0; i < tp && prime[i] <= limit && prime[i] <= num; ++i)
    if (num % prime[i] == 0) {
      yin[ty] = 1;
      while (num % prime[i] == 0) yin[ty] *= prime[i], num /= prime[i];
      ++ty;
    }
  if (num > 1) yin[ty++] = num;
}
void hebing(int x, int y) {
  while (fa[x] != -1) x = fa[x];
  while (fa[y] != -1) y = fa[y];
  if (x != y) fa[x] = y;
}
int renew(int x) {
  if (fa[x] == -1) return x;
  return fa[x] = renew(fa[x]);
}
void yin_div(int x, int cur, const int &l, int w) {
  if (cur == ty) {
    int y = num[l] / x;
    if (num[l] % 2) {
      int r, s, pos = 0;
      long long nm;
      if (x < y) swap(x, y);
      r = (x + y) / 2;
      s = (x - y) / 2;
      if ((r + s) % 2 == 0) return;
      nm = 2 * (long long)r * s;
      if (nm < 10000001 && ish[nm] != -1) {
        hebing(l, ish[nm]);
        renew(l);
        renew(ish[nm]);
      }
      nm = (long long)r * r + (long long)s * s;
      if (nm < 10000001 && ish[nm] != -1) {
        hebing(l, ish[nm]);
        renew(l);
        renew(ish[nm]);
      }
    } else {
      int pos = 0;
      long long nm;
      if (x % 4 && y % 4) return;
      if (x % 2 == 0)
        x /= 2;
      else
        y /= 2;
      if (x < y) swap(x, y);
      nm = (long long)x * x - (long long)y * y;
      if (nm < 10000001 && ish[nm] != -1) {
        hebing(l, ish[nm]);
        renew(l);
        renew(ish[nm]);
      }
      nm = (long long)x * x + (long long)y * y;
      if (nm < 10000001 && ish[nm] != -1) {
        hebing(l, ish[nm]);
        renew(l);
        renew(ish[nm]);
      }
    }
    return;
  }
  for (int i = cur; i < ty; ++i)
    yin_div(x *= (w ? yin[i] : 1), i + 1, l, w ^ 1);
}
void solve() {
  memset(ish, 255, sizeof(ish));
  for (int i = 0; i < n; ++i) ish[num[i]] = i;
  memset(fa, 255, sizeof(fa));
  for (int i = 0; i < n; ++i) {
    yin_cal(num[i]);
    for (int j = 0; j <= ty; ++j) yin_div(1, j, i, 1);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += fa[i] == -1;
  printf("%d\n", ans);
}
int main() {
  prime_cal();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &num[i]);
  solve();
  return 0;
}
