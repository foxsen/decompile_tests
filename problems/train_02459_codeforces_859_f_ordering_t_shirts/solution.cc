#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long a[400105], s[400105], t[400105], st[400105];
long long C, ans;
long long T[400105 * 4], lz[400105 * 4];
void Up(int rt, int l, int r) { T[rt] = max(T[(rt << 1)], T[(rt << 1 | 1)]); }
void Down(int rt, int l, int r) {
  if (lz[rt] != 0) {
    T[(rt << 1)] += lz[rt];
    lz[(rt << 1)] += lz[rt];
    T[(rt << 1 | 1)] += lz[rt];
    lz[(rt << 1 | 1)] += lz[rt];
    lz[rt] = 0;
  }
}
void upt(int rt, int l, int r, int L, int R, long long val) {
  if (R <= l || r <= L) return;
  if (L <= l && r <= R) {
    T[rt] += val;
    lz[rt] += val;
    return;
  }
  Down(rt, l, r);
  int mid = (l + r) / 2;
  upt((rt << 1), l, mid, L, R, val);
  upt((rt << 1 | 1), mid, r, L, R, val);
  Up(rt, l, r);
}
void uptS(int rt, int l, int r, int L, long long val) {
  if (l + 1 == r) {
    T[rt] = val;
    return;
  }
  Down(rt, l, r);
  int mid = (l + r) / 2;
  if (L <= mid)
    uptS((rt << 1), l, mid, L, val);
  else
    uptS((rt << 1 | 1), mid, r, L, val);
  Up(rt, l, r);
}
long long qy(int rt, int l, int r, int L, int R) {
  if (R <= l || r <= L) return 0;
  if (L <= l && r <= R) {
    return T[rt];
  }
  Down(rt, l, r);
  int mid = (l + r) / 2;
  return max(qy((rt << 1), l, mid, L, R), qy((rt << 1 | 1), mid, r, L, R));
}
void fmain(int tid) {
  scanf("%d%lld", &n, &C);
  for (int(i) = 1; (i) <= (int)(n + n - 1); (i)++) scanf("%lld", a + i);
  for (int(i) = 1; (i) <= (int)(n + n - 1); (i)++) s[i] = s[i - 1] + a[i];
  int i = 0;
  for (int(j) = 1; (j) <= (int)(n); (j)++) {
    while (i + 1 <= j && s[j + j - 1] - s[(i + 1) * 2 - 1 - 1] >= C) i++;
    if (i) {
      long long z = max(C - (st[j - 1] - st[i - 1]), 0LL);
      t[j] = max(t[j], z);
    }
    if (j > 1 && i < j - 1)
      upt(1, 0, n, i, j - 1, a[j * 2 - 1] + a[j * 2 - 2] - t[j - 1]);
    uptS(1, 0, n, j, a[j + j - 1]);
    long long z = qy(1, 0, n, i, j);
    t[j] = max(t[j], z);
    ans += t[j];
    st[j] = st[j - 1] + t[j];
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
