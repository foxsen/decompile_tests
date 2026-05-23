#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, m, fac[1010];
class PQ_Tree {
 private:
  int n;

 public:
  struct node {
    vector<int> son;
    int type, op, siz, cnt;
  } t[1010 << 1];
  int tot, rt;
  bool OK;
  bitset<1010> vis;
  void init(int _n) {
    tot = n = _n;
    rt = ++tot;
    for (int i = 1; i <= n; ++i) t[rt].son.push_back(i);
  }
  void dfs1(int u) {
    if (u <= n)
      return (void)(t[u].cnt = vis[u], t[u].siz = 1, t[u].op = vis[u] ? 2 : 1);
    t[u].op = t[u].siz = t[u].cnt = 0;
    for (auto v : t[u].son) {
      dfs1(v);
      t[u].cnt += t[v].cnt, t[u].siz += t[v].siz, t[u].op |= t[v].op;
    }
  }
  inline int GT(int u) { return t[u].cnt ? (t[u].cnt == t[u].siz ? 2 : 1) : 0; }
  int dfs2(int u, int lim) {
    if (!OK || t[u].op ^ 3) return u;
    vector<int> a[3];
    for (auto v : t[u].son) {
      a[GT(v)].push_back(v);
    }
    if ((lim > 0) + a[1].size() >= 3) {
      OK = false;
    }
    if (!lim) {
      for (auto &v : t[u].son) {
        if (t[v].cnt == t[u].cnt) {
          v = dfs2(v, 0);
          return u;
        }
      }
    }
    if (t[u].type) {
      int now = 0;
      vector<int> S;
      if (GT(t[u].son[0]) == 2 || !GT(t[u].son.back())) {
        reverse(t[u].son.begin(), t[u].son.end());
      }
      for (auto v : t[u].son) {
        int Type = GT(v);
        if (Type == 0) {
          S.push_back(v);
          now += now == 1;
        } else if (Type == 1) {
          if (now == 2) OK = false;
          ++now;
          int w = dfs2(v, 3 - now);
          S.insert(S.end(), t[w].son.begin(), t[w].son.end());
        } else {
          S.push_back(v);
          now += !now;
          if (now == 2) OK = false;
        }
      }
      if (lim && now == 2) OK = false;
      if (lim == 1) reverse(S.begin(), S.end());
      t[u].son = S;
    } else {
      int z = -1;
      if (a[2].size() == 1)
        z = a[2][0];
      else if (a[2].size() > 1)
        z = ++tot, t[z].type = 0, t[z].son = a[2];
      vector<int> S;
      if (!a[1].empty()) {
        int w = dfs2(a[1][0], 2);
        S.insert(S.end(), t[w].son.begin(), t[w].son.end());
      }
      if (~z) S.push_back(z);
      if (a[1].size() > 1) {
        int w = dfs2(a[1][1], 1);
        S.insert(S.end(), t[w].son.begin(), t[w].son.end());
      }
      if (a[0].empty()) {
        if (lim == 1) reverse(S.begin(), S.end());
        t[u].type = 1, t[u].son = S;
      } else {
        if (lim) {
          t[u].son.clear();
          t[u].type = 1;
          z = a[0][0];
          if (a[0].size() > 1) {
            z = ++tot, t[z].type = 0, t[z].son = a[0];
          }
          t[u].son.push_back(z);
          t[u].son.insert(t[u].son.end(), S.begin(), S.end());
          if (lim == 1) reverse(t[u].son.begin(), t[u].son.end());
        } else {
          z = S[0];
          if (S.size() > 1) z = ++tot, t[z].son = S, t[z].type = 1;
          t[u].son = a[0], t[u].son.push_back(z);
        }
      }
    }
    return u;
  }
  bool Insert(const bitset<1010> &B) {
    vis = B;
    dfs1(rt);
    OK = true;
    rt = dfs2(rt, 0);
    return OK;
  }
  int calc(int u) {
    if (u <= n) return 1;
    int ans = t[u].type ? 2 : fac[t[u].son.size()];
    for (auto v : t[u].son) ans = 1LL * ans * calc(v) % mod;
    return ans;
  }
} T;
int main() {
  n = read(), m = read();
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
  }
  T.init(n);
  while (m--) {
    static bitset<1010> B;
    B.reset();
    int k = read();
    while (k--) B[read()] = 1;
    if (!T.Insert(B)) {
      puts("0");
      return 0;
    }
  }
  printf("%d\n", T.calc(T.rt));
  return 0;
}
