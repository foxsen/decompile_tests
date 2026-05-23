#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
template <typename _T>
inline void read(_T &f) {
  f = 0;
  _T fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fu = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  f *= fu;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + 48);
  else
    print(x / 10), putchar(x % 10 + 48);
}
template <typename T>
void print(T x, char t) {
  print(x);
  putchar(t);
}
const int N = 4e5 + 5;
struct ele {
  int u, v, val;
  ele(int a = 0, int b = 0, int c = 0) : u(a), v(b), val(c) {}
};
bool operator<(const ele a, const ele b) {
  if (a.u != b.u) return a.u < b.u;
  return a.v < b.v;
}
map<ele, pair<int, int> > wxw;
map<ele, pair<int, int> >::iterator it;
vector<ele> t[N << 2], Q[N];
int fa[N], w[N], siz[N], ans[N], st[N];
int n, m, q, tot, cntq, top;
int find(int x) {
  while (fa[x] != x) x = fa[x];
  return x;
}
int dis(int x) {
  int ans = 0;
  while (fa[x] != x) {
    ans ^= w[x];
    x = fa[x];
  }
  return ans;
}
void change(int u, int l, int r, int L, int R, ele x) {
  if (l <= L && R <= r) {
    t[u].push_back(x);
    return;
  }
  int mid = (L + R) >> 1;
  if (mid >= l) change(u << 1, l, r, L, mid, x);
  if (mid + 1 <= r) change(u << 1 | 1, l, r, mid + 1, R, x);
}
struct lbase_t {
  int a[30];
  void insert(int x) {
    for (register int i = 29; i >= 0; i--) {
      if ((x >> i) & 1) {
        if (!a[i]) {
          a[i] = x;
          break;
        }
        x ^= a[i];
      }
    }
  }
  int query(int x) {
    for (register int i = 29; i >= 0; i--) {
      if ((x ^ a[i]) < x) x ^= a[i];
    }
    return x;
  }
} tb[30];
void query(int u, int l, int r, int dep) {
  int now = top;
  tb[dep] = tb[dep - 1];
  for (register int i = 0; i < (int)t[u].size(); i++) {
    int x = find(t[u][i].u), y = find(t[u][i].v);
    if (x == y) {
      tb[dep].insert(dis(t[u][i].u) ^ dis(t[u][i].v) ^ t[u][i].val);
      continue;
    }
    int val = dis(t[u][i].u) ^ dis(t[u][i].v) ^ t[u][i].val;
    if (siz[x] >= siz[y]) swap(x, y);
    fa[x] = y;
    siz[y] += siz[x];
    w[x] = val;
    st[++top] = x;
  }
  if (l != r) {
    int mid = (l + r) >> 1;
    query(u << 1, l, mid, dep + 1);
    query(u << 1 | 1, mid + 1, r, dep + 1);
  }
  if (l == r) {
    for (register int i = 0; i < (int)Q[l].size(); i++) {
      ans[Q[l][i].val] = tb[dep].query(dis(Q[l][i].u) ^ dis(Q[l][i].v));
    }
  }
  while (top != now) {
    int x = st[top--], y = fa[x];
    siz[y] -= siz[x];
    fa[x] = x;
    w[x] = 0;
  }
}
int main() {
  read(n);
  read(m);
  for (register int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  for (register int i = 1; i <= m; i++) {
    int u, v, val;
    read(u);
    read(v);
    read(val);
    wxw[ele(u, v)] = make_pair(val, ++tot);
  }
  read(q);
  for (register int i = 1; i <= q; i++) {
    int opt;
    read(opt);
    if (opt == 1) {
      int u, v, val;
      read(u);
      read(v);
      read(val);
      wxw[ele(u, v)] = make_pair(val, ++tot);
    }
    if (opt == 2) {
      int u, v;
      read(u);
      read(v);
      pair<int, int> tmp = wxw[ele(u, v)];
      wxw.erase(ele(u, v));
      change(1, tmp.second, tot, 1, m + q, ele(u, v, tmp.first));
      ++tot;
    }
    if (opt == 3) {
      int u, v;
      read(u);
      read(v);
      Q[tot].push_back(ele(u, v, ++cntq));
    }
  }
  for (it = wxw.begin(); it != wxw.end(); ++it)
    change(1, (it->second).second, m + q, 1, m + q,
           ele((it->first).u, (it->first).v, (it->second).first));
  query(1, 1, m + q, 1);
  for (register int i = 1; i <= cntq; i++) print(ans[i], '\n');
  return 0;
}
