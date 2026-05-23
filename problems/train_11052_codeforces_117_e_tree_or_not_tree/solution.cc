#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
const int MAXM = 2 * MAXN;
int n, m;
int to[MAXM], nxt[MAXM], head[MAXN], E;
struct ST {
  vector<int> t;
  vector<int> rev;
  ST() {}
  void resize(int sz) {
    t.resize(sz);
    rev.resize(sz);
  }
  void inverse(int l, int r) { inverse(1, 0, t.size() / 2, l, r); }
  inline void push(int v, int tl, int tr) {
    if (rev[v]) {
      int len = tr - tl;
      t[v] = len - t[v];
      if (tl + 1 != tr) {
        rev[v << 1] ^= 1;
        rev[v << 1 | 1] ^= 1;
      }
      rev[v] = 0;
    }
  }
  void inverse(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l >= r) return;
    if (tl == l && tr == r) {
      int len = tr - tl;
      t[v] = len - t[v];
      if (tl + 1 != tr) {
        rev[v << 1] ^= 1;
        rev[v << 1 | 1] ^= 1;
      }
      return;
    }
    int tm = (tl + tr) >> 1;
    inverse(v << 1, tl, tm, l, min(r, tm));
    inverse(v << 1 | 1, tm, tr, max(l, tm), r);
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
  int getSum(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l >= r) return 0;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) >> 1;
    return getSum(v << 1, tl, tm, l, min(r, tm)) +
           getSum(v << 1 | 1, tm, tr, max(l, tm), r);
  }
  int getSum(int l, int r) { return getSum(1, 0, t.size(), l, r); }
};
int p[MAXN];
int color[MAXN];
int start;
vector<int> cycle;
ST cycleSt;
int posInCycle[MAXN];
int sz[MAXN];
vector<ST> st;
int par[17][MAXN];
vector<vector<int>> path;
int posInPath[MAXN];
int offOutsideCycle, offInsideCycle;
int d[MAXN];
void addEdge(int a, int b) {
  to[E] = b;
  nxt[E] = head[a];
  head[a] = E++;
  to[E] = a;
  nxt[E] = head[b];
  head[b] = E++;
}
void update(int a, int b) {
  while (color[a] != color[b]) {
    int aa = path[color[a]][0];
    int bb = path[color[b]][0];
    if (d[aa] < d[bb]) {
      swap(aa, bb);
      swap(a, b);
    }
    offOutsideCycle -= st[color[aa]].t[1];
    st[color[aa]].inverse(0, posInPath[a] + 1);
    offOutsideCycle += st[color[aa]].t[1];
    a = par[0][aa];
  }
  if (posInPath[a] > posInPath[b]) swap(a, b);
  offOutsideCycle -= st[color[a]].t[1];
  st[color[a]].inverse(posInPath[a] + 1, posInPath[b] + 1);
  offOutsideCycle += st[color[a]].t[1];
}
int solve(int a, int b) {
  int aa = par[16][par[16][a]];
  int bb = par[16][par[16][b]];
  if (aa == bb) {
    update(a, b);
  } else {
    update(a, aa);
    update(b, bb);
    a = aa;
    b = bb;
    if (posInCycle[a] > posInCycle[b]) swap(a, b);
    int k = cycle.size();
    int inside = posInCycle[b] - posInCycle[a];
    if (inside * 2 < k) {
      offInsideCycle -= cycleSt.t[1];
      cycleSt.inverse(posInCycle[a], posInCycle[b]);
      offInsideCycle += cycleSt.t[1];
    } else if (inside * 2 > k) {
      offInsideCycle -= cycleSt.t[1];
      cycleSt.inverse(0, posInCycle[a]);
      cycleSt.inverse(posInCycle[b], k);
      offInsideCycle += cycleSt.t[1];
    } else {
      assert(cycle[(posInCycle[a] + k / 2) % k] == b);
      a = aa;
      b = bb;
      if (posInCycle[a] < posInCycle[b]) {
        if (cycle[(posInCycle[a] + 1) % k] <
            cycle[(posInCycle[a] + k - 1) % k]) {
          offInsideCycle -= cycleSt.t[1];
          cycleSt.inverse(posInCycle[a], posInCycle[b]);
          offInsideCycle += cycleSt.t[1];
        } else {
          offInsideCycle -= cycleSt.t[1];
          cycleSt.inverse(0, posInCycle[a]);
          cycleSt.inverse(posInCycle[b], k);
          offInsideCycle += cycleSt.t[1];
        }
      } else {
        if (cycle[(posInCycle[a] + 1) % k] >
            cycle[(posInCycle[a] + k - 1) % k]) {
          offInsideCycle -= cycleSt.t[1];
          cycleSt.inverse(posInCycle[b], posInCycle[a]);
          offInsideCycle += cycleSt.t[1];
        } else {
          offInsideCycle -= cycleSt.t[1];
          cycleSt.inverse(0, posInCycle[b]);
          cycleSt.inverse(posInCycle[a], k);
          offInsideCycle += cycleSt.t[1];
        }
      }
    }
  }
  return offOutsideCycle + max(1, offInsideCycle);
}
int pow2Up(int n) {
  while (n & (n - 1)) n += -n & n;
  return n;
}
bool findCycle(int v, int par = -1) {
  color[v] = 1;
  for (int id = head[v]; ~id; id = nxt[id]) {
    if (to[id] == par) continue;
    if (color[to[id]] == 1) {
      start = to[id];
      return true;
    }
    if (!color[to[id]]) {
      if (findCycle(to[id], v)) {
        p[v] = to[id];
        return true;
      }
    }
  }
  color[v] = 2;
  return false;
}
void dfs(int v, int parent) {
  sz[v] = 1;
  par[0][v] = parent;
  for (int i = 1; i < 17; ++i) {
    par[i][v] = par[i - 1][par[i - 1][v]];
  }
  int maxSon = -1;
  for (int id = head[v]; ~id; id = nxt[id]) {
    if (to[id] != parent && posInCycle[to[id]] == -1) {
      d[to[id]] = d[v] + 1;
      dfs(to[id], v);
      sz[v] += sz[to[id]];
      if (maxSon == -1 || sz[maxSon] < sz[to[id]]) maxSon = to[id];
    }
  }
  if (maxSon == -1) {
    color[v] = path.size();
    path.push_back(vector<int>());
    path.back().push_back(v);
  } else {
    color[v] = color[maxSon];
    path[color[maxSon]].push_back(v);
  }
}
int main() {
  memset(head, 0xff, sizeof head);
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < n; ++i) {
    scanf("%d%d", &a, &b);
    addEdge(--a, --b);
  }
  memset(p, 0xff, sizeof p);
  for (int i = 0; i < n; ++i) {
    if (!color[i] && findCycle(i)) {
      int v = start;
      while (v != -1) {
        cycle.push_back(v);
        v = p[v];
      }
      break;
    }
  }
  cycleSt.resize(2 * pow2Up(cycle.size()));
  cycleSt.inverse(0, cycle.size());
  offInsideCycle = cycleSt.t[1];
  memset(posInCycle, 0xff, sizeof posInCycle);
  for (int i = 0; i < (int)cycle.size(); ++i) {
    posInCycle[cycle[i]] = i;
  }
  for (int i = 0; i < (int)cycle.size(); ++i) {
    dfs(cycle[i], cycle[i]);
  }
  for (int i = 0; i < (int)path.size(); ++i) {
    reverse(path[i].begin(), path[i].end());
    for (int j = 0; j < (int)path[i].size(); ++j) posInPath[path[i][j]] = j;
    st.push_back(ST());
    st.back().resize(2 * pow2Up(path[i].size()));
    st.back().inverse(posInCycle[path[i][0]] != -1, path[i].size());
    offOutsideCycle += st.back().t[1];
  }
  for (int tc = 1, a, b; tc <= m; ++tc) {
    scanf("%d%d", &a, &b);
    printf("%d\n", solve(--a, --b));
  }
  return 0;
}
