#include <bits/stdc++.h>
template <typename T>
void read(T &);
template <typename T>
void write(const T &);
const int iinf = 2147483647;
const long long llinf = 9223372036854775807ll;
const int N = 500005;
void dfs1(int u, int fa);
void dfs2(int u, int fa);
std::vector<int> G[N];
int siz[N];
long long ans[N];
int n;
int main() {
  read(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v);
    G[u].push_back(v), G[v].push_back(u);
  }
  dfs1(1, 0);
  ans[1] = 1ll * n * (n - 1) / 2;
  dfs2(1, 0);
  int as = 1;
  for (int i = 2; i <= n; ++i) {
    if (ans[i] > ans[as]) as = i;
  }
  dfs1(as, 0);
  ans[as] = 1ll * n * (n - 1) / 2;
  dfs2(as, 0);
  as = 1;
  for (int i = 2; i <= n; ++i) {
    if (ans[i] > ans[as]) as = i;
  }
  write(ans[as]), putchar('\n');
  return 0;
}
void dfs1(int u, int fa) {
  siz[u] = 1;
  for (int v : G[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    siz[u] += siz[v];
  }
}
void dfs2(int u, int fa) {
  for (int v : G[u]) {
    if (v == fa) continue;
    ans[v] = ans[u] + 1ll * siz[v] * (siz[u] - siz[v]);
    dfs2(v, u);
  }
}
template <typename T>
void read(T &Re) {
  T k = 0;
  char ch = getchar();
  int flag = 1;
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while ((ch >= '0' && ch <= '9')) k = k * 10 + ch - '0', ch = getchar();
  Re = flag * k;
}
template <typename T>
void write(const T &Wr) {
  if (Wr < 0) {
    putchar('-'), write(-Wr);
  } else if (Wr < 10) {
    putchar(Wr + '0');
  } else {
    write(Wr / 10), putchar((Wr % 10) + '0');
  }
}
