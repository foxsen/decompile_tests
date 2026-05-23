#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const long long inf = 1e18;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() {
  return pp1 == pp2 &&
                 (pp2 = (pp1 = buf) + fread(buf, 1, 1 << 12, stdin), pp1 == pp2)
             ? EOF
             : *pp1++;
}
inline int read() {
  int x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
int n, m, a[MAXN];
long long p;
vector<long long> S[MAXN << 2];
long long sum[MAXN << 2];
int len[MAXN << 2];
inline void pushup(int x) {
  sum[x] = sum[x << 1] + sum[x << 1 | 1];
  for (int i = 0, j = 0; i <= len[x << 1]; i++) {
    if (j > len[x << 1 | 1]) j--;
    for (; j <= len[x << 1 | 1]; j++) {
      long long t1 = S[x << 1 | 1][j] + i * p - sum[x << 1],
                t2 = S[x << 1][i + 1] - 1 - i * p + sum[x << 1];
      if (t2 < S[x << 1 | 1][j]) {
        if (j) j--;
        break;
      }
      S[x][i + j] = min(S[x][i + j], max(S[x << 1][i], t1));
    }
  }
}
inline void Build(int x, int l, int r) {
  for (int i = 0; i <= r - l + 2; i++) S[x].push_back(inf);
  S[x][0] = -inf, len[x] = r - l + 1;
  if (l == r) {
    S[x][1] = p - a[l], sum[x] = a[l];
    return;
  }
  int mid = l + r >> 1;
  Build(x << 1, l, mid), Build(x << 1 | 1, mid + 1, r), pushup(x);
}
inline long long Ask(int x, int l, int r, int ql, int qr, long long tmp) {
  if (ql <= l && r <= qr)
    return tmp + sum[x] -
           p * (upper_bound(S[x].begin(), S[x].end(), tmp) - S[x].begin() - 1);
  int mid = l + r >> 1;
  if (qr <= mid)
    return Ask(x << 1, l, mid, ql, qr, tmp);
  else if (ql > mid)
    return Ask(x << 1 | 1, mid + 1, r, ql, qr, tmp);
  else {
    long long tt = Ask(x << 1, l, mid, ql, mid, tmp);
    return Ask(x << 1 | 1, mid + 1, r, mid + 1, qr, tt);
  }
}
int main() {
  n = read(), m = read(), p = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  Build(1, 1, n);
  for (int l, r; m--;)
    l = read(), r = read(), cout << Ask(1, 1, n, l, r, 0) << '\n';
  return 0;
}
