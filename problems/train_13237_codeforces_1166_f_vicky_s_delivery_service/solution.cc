#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp[100001];
long long n, m, q, u, v, c, f[100001];
set<long long> a[100001];
char op;
inline long long read() {
  long long sum = 0, x = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    sum = (sum << 1) + (sum << 3) + (ch ^ '0');
    ch = getchar();
  }
  return sum * x;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline long long find(long long x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}
inline void jh(long long x, long long y) {
  long long u = find(x), v = find(y);
  if (u == v) return;
  if (a[u].size() < a[v].size()) swap(u, v);
  f[v] = u;
  for (long long i : a[v]) a[u].insert(i);
  a[v].clear();
}
inline void add(long long u, long long v, long long c) {
  a[find(u)].insert(v);
  if (mp[u].count(c)) {
    long long x = mp[u][c];
    jh(v, x);
  } else
    mp[u][c] = v;
}
signed main() {
  n = read();
  m = read();
  read();
  q = read();
  for (register long long i = 1; i <= n; ++i) f[i] = i;
  while (m--) {
    u = read();
    v = read();
    c = read();
    add(u, v, c);
    add(v, u, c);
  }
  while (q--) {
    cin >> op;
    u = read();
    v = read();
    if (op == '+') {
      c = read();
      add(u, v, c);
      add(v, u, c);
    } else {
      long long x = find(u), y = find(v);
      if (x == y || a[x].count(v))
        puts("Yes");
      else
        puts("No");
    }
  }
  return 0;
}
