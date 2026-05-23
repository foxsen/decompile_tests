#include <bits/stdc++.h>
using namespace std;
inline int qr() {
  int f = 0, fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fu = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + c - 48;
    c = getchar();
  }
  return f * fu;
}
const int N = 1e5 + 10;
int head[N], ver[N << 1], Next[N << 1], tot;
int n, T, a, b, da, db;
int d[N];
vector<int> seq;
int mx = 0;
inline void add(int x, int y) {
  ver[++tot] = y;
  Next[tot] = head[x];
  head[x] = tot;
}
inline void init() {
  memset(head, 0, sizeof(int) * (n + 1));
  memset(d, 0, sizeof(int) * (n + 1));
  tot = 0, seq.clear();
}
void dp(int x, int f) {
  for (int i = head[x]; i; i = Next[i]) {
    int y = ver[i];
    if (y == f) continue;
    dp(y, x);
    mx = max(mx, d[x] + d[y] + 1);
    d[x] = max(d[x], d[y] + 1);
  }
}
bool dfs(int x, int f) {
  bool flag = false;
  for (register int i = head[x]; i; i = Next[i]) {
    int y = ver[i];
    if (y == f) continue;
    if (dfs(y, x)) flag = true;
  }
  return x == a || flag ? seq.push_back(x), true : false;
}
int main() {
  T = qr();
  while (T--) {
    n = qr(), a = qr(), b = qr(), da = qr(), db = qr();
    init();
    for (register int i = 1; i <= n - 1; ++i) {
      int x = qr(), y = qr();
      add(x, y), add(y, x);
    }
    if (db <= 2 * da) {
      puts("Alice");
      continue;
    }
    dfs(b, 0);
    if (seq.size() <= da + 1) {
      puts("Alice");
      continue;
    }
    mx = 0, dp(1, 0);
    if (mx > 2 * da)
      puts("Bob");
    else
      puts("Alice");
  }
  return 0;
}
