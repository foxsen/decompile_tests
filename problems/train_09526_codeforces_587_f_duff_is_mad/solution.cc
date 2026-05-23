#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
char s[MAXN];
int n, q, sl[MAXN], sr[MAXN];
long long sum[MAXN], ans[MAXN];
struct Query {
  int id, x, y;
  Query() {}
  Query(int _id, int _x, int _y) : id(_id), x(_x), y(_y) {}
};
vector<Query> q1[MAXN], q2[MAXN];
struct AC_Automaton {
  int tot, ch[MAXN][26], fail[MAXN], edp[MAXN];
  int q[MAXN], in[MAXN], out[MAXN], clk;
  vector<int> e[MAXN];
  void Insert(int id, int l, int r) {
    int p = 0;
    for (int i = l; i <= r; ++i) {
      int x = (s[i] - 'a');
      if (!ch[p][x]) {
        ch[p][x] = ++tot;
      }
      p = ch[p][x];
    }
    edp[id] = p;
  }
  void FailTree(int u) {
    in[u] = ++clk;
    for (auto v : e[u]) {
      FailTree(v);
    }
    out[u] = clk;
  }
  void GetFail() {
    int head = 1, tail = 0;
    for (int i = 0; i < 26; ++i) {
      if (ch[0][i]) {
        q[++tail] = ch[0][i];
      }
    }
    while (head <= tail) {
      int u = q[head++];
      e[fail[u]].push_back(u);
      for (int i = 0; i < 26; ++i) {
        if (ch[u][i]) {
          fail[ch[u][i]] = ch[fail[u]][i];
          q[++tail] = ch[u][i];
        } else {
          ch[u][i] = ch[fail[u]][i];
        }
      }
    }
    FailTree(0);
  }
} ac;
struct Block {
  int siz, bcnt, L[MAXN], R[MAXN], bel[MAXN];
  int a[MAXN], tag[MAXN];
  void Build(int m) {
    siz = sqrt(m);
    for (int l = 1; l <= m; l += siz) {
      int r = min(m, l + siz - 1);
      L[++bcnt] = l;
      R[bcnt] = r;
      for (int i = l; i <= r; ++i) {
        bel[i] = bcnt;
      }
    }
  }
  void Modify(int l, int r, int v) {
    int bl = bel[l], br = bel[r];
    if (bl == br) {
      for (int i = l; i <= r; ++i) {
        a[i] += v;
      }
    } else {
      for (int i = l; i <= R[bl]; ++i) {
        a[i] += v;
      }
      for (int i = bl + 1; i < br; ++i) {
        tag[i] += v;
      }
      for (int i = L[br]; i <= r; ++i) {
        a[i] += v;
      }
    }
  }
  int Query(int x) { return a[x] + tag[bel[x]]; }
} blk;
long long GetAns1(int x) {
  int p = 0;
  long long ret = 0;
  for (int i = sl[x]; i <= sr[x]; ++i) {
    p = ac.ch[p][s[i] - 'a'];
    ret += blk.Query(ac.in[p]);
  }
  return ret;
}
void GetAns2(int x) {
  memset(blk.a, 0, sizeof(blk.a));
  memset(blk.tag, 0, sizeof(blk.tag));
  int p = 0;
  for (int i = sl[x]; i <= sr[x]; ++i) {
    p = ac.ch[p][s[i] - 'a'];
    blk.Modify(ac.in[p], ac.clk, 1);
  }
  for (int i = 1; i <= n; ++i) {
    int u = ac.edp[i];
    sum[i] = sum[i - 1] + blk.Query(ac.out[u]) - blk.Query(ac.in[u] - 1);
  }
  for (auto v : q2[x]) {
    ans[v.id] = sum[v.y] - sum[v.x - 1];
  }
}
void init() {
  read(n);
  read(q);
  for (int i = 1; i <= n; ++i) {
    sl[i] = sr[i - 1] + 1;
    scanf("%s", s + sl[i]);
    sr[i] = sr[i - 1] + strlen(s + sl[i]);
    ac.Insert(i, sl[i], sr[i]);
  }
  ac.GetFail();
  blk.Build(ac.clk);
  for (int i = 1; i <= q; ++i) {
    int l, r, k;
    read(l);
    read(r);
    read(k);
    if (sr[k] - sl[k] + 1 <= blk.siz) {
      q1[l - 1].push_back(Query(i, k, -1));
      q1[r].push_back(Query(i, k, 1));
    } else {
      q2[k].push_back(Query(i, l, r));
    }
  }
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    int u = ac.edp[i];
    blk.Modify(ac.in[u], ac.out[u], 1);
    for (auto v : q1[i]) {
      ans[v.id] += GetAns1(v.x) * v.y;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (sr[i] - sl[i] + 1 <= blk.siz) continue;
    GetAns2(i);
  }
  for (int i = 1; i <= q; ++i) {
    printf("%lld\n", ans[i]);
  }
}
int main() {
  init();
  solve();
  return 0;
}
