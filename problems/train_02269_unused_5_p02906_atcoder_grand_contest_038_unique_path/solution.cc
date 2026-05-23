#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

#define int long long

const int maxn = 2e5 + 10;
int n, m, q, tot;

struct Querys {
  int op, u, v;
} Q[maxn];

int par[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  if ((x = find(x)) != ((y = find(y)))) {
    par[x] = y, tot--;
  }
}

signed main() {
  scanf("%lld %lld %lld", &n, &m, &q);
  tot = n;
  rep(i, 1, n) par[i] = i;
  rep(i, 1, q) {
    int u, v, op;
    scanf("%lld %lld %lld", &u, &v, &op);
    Q[i] = Querys{op, ++u, ++v};
    if (!op) unite(u, v);
    if (m == n - 1 && Q[i].op) {
      return puts("No"), 0;
    }
  }
  if (m == n - 1) {
    return puts("Yes"), 0;
  }
  rep(i, 1, q) {
    if (Q[i].op && find(Q[i].u) == find(Q[i].v)) {
      return puts("No"), 0;
    }
  }
  if (m >= n && m <= n - tot + tot * (tot - 1) / 2) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}