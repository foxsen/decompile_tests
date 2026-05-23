#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  int ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void rt(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    rt(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
const int maxn = 5005;
pair<int, int> yz[2];
int nol, n, to[maxn], nx[maxn], hd[maxn], cnt;
bool f[maxn];
void addedge(int u, int v) {
  to[cnt] = v;
  nx[cnt] = hd[u];
  hd[u] = cnt++;
}
int dep[maxn], size[maxn], fa[maxn];
void work(int v) {
  for (int i = int(nol / 2); i >= (int)(v); i--) f[i] |= f[i - v];
}
void noans() {
  puts("NO");
  exit(0);
}
int main() {
  n = rd();
  for (int i = int(0); i <= (int)(1); i++)
    yz[i].first = rd(), yz[i].second = rd();
  memset(hd, -1, sizeof hd);
  for (int i = int(1); i <= (int)(n); i++) size[i] = 1;
  for (int v = int(2); v <= (int)(n); v++) {
    fa[v] = rd();
    addedge(fa[v], v);
    size[fa[v]] = 0;
  }
  for (int i = int(1); i <= (int)(n); i++) nol += size[i];
  if (nol & 1) noans();
  for (int i = int(2); i <= (int)(n); i++) dep[i] = dep[fa[i]] + 1;
  for (int i = int(n); i >= (int)(2); i--) size[fa[i]] += size[i];
  for (int _ = int(0); _ <= (int)(1); _++) {
    int a = yz[_].first, b = yz[_].second;
    memset(f, 0, sizeof f);
    f[1] = 1;
    int p1, p2;
    for (p1 = a; fa[p1] != 1; p1 = fa[p1]) {
      for (int i = hd[fa[p1]]; ~i; i = nx[i]) {
        int v = to[i];
        if (v == p1) continue;
        work(size[v]);
      }
    }
    for (p2 = b; fa[p2] != 1; p2 = fa[p2]) {
      for (int i = hd[fa[p2]]; ~i; i = nx[i]) {
        int v = to[i];
        if (v == p2) continue;
        work(size[v]);
      }
    }
    for (int i = hd[1]; ~i; i = nx[i]) {
      int v = to[i];
      if (v == p1 || v == p2) continue;
      work(size[v]);
    }
    if (!f[nol / 2]) noans();
  }
  puts("YES");
}
