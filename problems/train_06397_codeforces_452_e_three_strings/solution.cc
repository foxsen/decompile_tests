#include <bits/stdc++.h>
using namespace std;
template <class T>
T inline sqr(T x) {
  return x * x;
}
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 1e-8;
const int MAXN = 1000500;
string s;
int n;
int fin[3];
struct node {
  int l, r, par, link;
  map<char, int> next;
  node(int l = 0, int r = 0, int par = -1) : l(l), r(r), par(par), link(-1) {}
  int len() { return r - l; }
  int &get(char c) {
    if (!next.count(c)) next[c] = -1;
    return next[c];
  }
};
node t[MAXN];
int sz;
struct state {
  int v, pos;
  state(int v, int pos) : v(v), pos(pos) {}
};
state ptr(0, 0);
state go(state st, int l, int r) {
  while (l < r)
    if (st.pos == t[st.v].len()) {
      st = state(t[st.v].get(s[l]), 0);
      if (st.v == -1) return st;
    } else {
      if (s[t[st.v].l + st.pos] != s[l]) return state(-1, -1);
      if (r - l < t[st.v].len() - st.pos) return state(st.v, st.pos + r - l);
      l += t[st.v].len() - st.pos;
      st.pos = t[st.v].len();
    }
  return st;
}
int split(state st) {
  if (st.pos == t[st.v].len()) return st.v;
  if (st.pos == 0) return t[st.v].par;
  node v = t[st.v];
  int id = sz++;
  t[id] = node(v.l, v.l + st.pos, v.par);
  t[v.par].get(s[v.l]) = id;
  t[id].get(s[v.l + st.pos]) = st.v;
  t[st.v].par = id;
  t[st.v].l += st.pos;
  return id;
}
int get_link(int v) {
  if (t[v].link != -1) return t[v].link;
  if (t[v].par == -1) return 0;
  int to = get_link(t[v].par);
  return t[v].link = split(
             go(state(to, t[to].len()), t[v].l + (t[v].par == 0), t[v].r));
}
void tree_extend(int pos) {
  for (;;) {
    state nptr = go(ptr, pos, pos + 1);
    if (nptr.v != -1) {
      ptr = nptr;
      return;
    }
    int mid = split(ptr);
    int leaf = sz++;
    t[leaf] = node(pos, n, mid);
    t[mid].get(s[pos]) = leaf;
    ptr.v = get_link(mid);
    ptr.pos = t[ptr.v].len();
    if (!mid) break;
  }
}
void build_tree() {
  sz = 1;
  for (int i = 0; i < n; ++i) tree_extend(i);
}
long long d[MAXN][3];
long long ans[MAXN];
const int MOD = 1e9 + 7;
long long bal[MAXN];
void add(int l, int r, int val) {
  bal[l] += val;
  bal[r + 1] -= val;
}
void dfs(int v, int len) {
  for (auto w : ::t[v].next) {
    int nlen = len + ::t[w.second].len();
    dfs(w.second, nlen);
  }
  int tt = -1;
  for (int i = 0; i < (int)(3); ++i)
    if (fin[i] >= t[v].l && fin[i] < t[v].r) {
      tt = i;
      break;
    }
  if (tt != -1)
    d[v][tt] = 1;
  else {
    for (auto w : ::t[v].next) {
      for (int i = 0; i < (int)(3); ++i) d[v][i] += d[w.second][i];
    }
    long long c = 1;
    for (int i = 0; i < (int)(3); ++i) c = (c * d[v][i]) % MOD;
    add(len - t[v].len() + 1, len, c);
  }
}
int main() {
  vector<string> in(3);
  for (int i = 0; i < (int)(3); ++i) {
    cin >> in[i];
    s += in[i];
    fin[i] = s.length();
    s += char('0' + i);
  }
  n = s.length();
  build_tree();
  dfs(0, 0);
  int l = 1e9;
  for (int i = 0; i < (int)(3); ++i) l = min(l, (int)in[i].length());
  long long z = 0;
  for (int i = 0; i < (int)(MAXN); ++i) {
    z += bal[i];
    z %= MOD;
    z = (z + MOD) % MOD;
    ans[i] = z;
  }
  for (int i = 1; i <= (int)(l); ++i) printf("%d ", (int)ans[i]);
  return 0;
}
