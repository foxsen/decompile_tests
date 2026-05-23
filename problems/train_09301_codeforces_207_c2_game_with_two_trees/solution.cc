#include <bits/stdc++.h>
using namespace std;
class fenv_tree {
  static int f(int x) { return x & -x; }
  vector<int> tr;

 public:
  void add(int x, int v) {
    assert(0 <= x && x + 1 < ((int)(tr).size()));
    for (x++; x < ((int)(tr).size()); x += f(x)) tr[x] += v;
  }
  int get(int x) {
    assert(-1 <= x && x + 1 < ((int)(tr).size()));
    int res = 0;
    for (x++; x > 0; x -= f(x)) res += tr[x];
    return res;
  }
  fenv_tree(int n = 0) : tr(n + 1) {}
};
const unsigned long long P = 29;
const int K = 17;
const int MAXN = 1e5 + 1e3;
unsigned long long PPOW[MAXN + 1];
struct _node;
struct Up {
  _node *x;
  unsigned long long h, hrev;
  Up() : x(0), h(0), hrev(0) {}
  Up(_node *x, unsigned long long h, unsigned long long hrev)
      : x(x), h(h), hrev(hrev) {}
};
typedef struct _node {
  _node *ne[26];
  int cnt;
  Up ups[K];
  unsigned long long sumhrev;
  int depth;
  _node() : cnt(0), sumhrev(0), depth(0) { memset(ne, 0, sizeof ne); }
  pair<int, int> eulerIds;
  int sufpos;
} * node;
bool cmp(node v1, node v2) {
  if (v1 == v2) return false;
  assert(v1 && v2);
  for (int i = K - 1; i >= 0; i--)
    if (v1->ups[i].h == v2->ups[i].h) {
      v1 = v1->ups[i].x;
      v2 = v2->ups[i].x;
      assert(v1);
      assert(v2);
    }
  assert(v1->ups[0].h != v2->ups[0].h);
  return v1->ups[0].h < v2->ups[0].h;
}
unsigned long long gethr(node base, int step, int len) {
  step = base->depth - step - len;
  assert(step >= 0);
  for (int i = K - 1; i >= 0; i--)
    if (step >= (1 << i)) {
      base = base->ups[i].x;
      step -= 1 << i;
      assert(base);
    }
  unsigned long long res = 0;
  for (int i = K - 1; i >= 0; i--)
    if (len >= (1 << i)) {
      res = res * PPOW[1 << i] + base->ups[i].hrev;
      base = base->ups[i].x;
      len -= 1 << i;
    }
  return res;
}
bool cmp2(node v1, node v2) {
  int clen = 0;
  for (int i = K - 1; i >= 0; i--) {
    if (((clen + (1 << i)) <= v2->depth) &&
        v1->ups[i].h == gethr(v2, clen, (1 << i))) {
      v1 = v1->ups[i].x;
      clen += 1 << i;
      assert(v1);
    }
  }
  if (clen >= v2->depth) return false;
  assert(v1->ups[0].h != gethr(v2, clen, 1));
  return v1->ups[0].h < gethr(v2, clen, 1);
}
bool cmp3(node v1, node v2) {
  int clen = 0;
  for (int i = K - 1; i >= 0; i--) {
    if (((clen + (1 << i)) <= v2->depth) &&
        v1->ups[i].h == gethr(v2, clen, (1 << i))) {
      v1 = v1->ups[i].x;
      clen += 1 << i;
      assert(v1);
    }
  }
  if (clen >= v2->depth) return true;
  assert(v1->ups[0].h != gethr(v2, clen, 1));
  return v1->ups[0].h < gethr(v2, clen, 1);
}
class Tree {
  vector<node> ns;

 public:
  Tree() : ns(1, new _node()) { ns[0]->cnt++; }
  node add(int v, char c) {
    assert(0 <= v && v < ((int)(ns).size()));
    assert('a' <= c && c <= 'z');
    node vv = ns[v];
    node x = vv->ne[c - 'a'];
    if (!x) {
      x = vv->ne[c - 'a'] = new _node();
      x->depth = vv->depth + 1;
      x->sumhrev = vv->sumhrev * P + c;
      x->ups[0] = Up(vv, c, c);
      for (int i = 1; i < K; i++) {
        Up a = x->ups[i - 1];
        Up b;
        if (a.x) b = a.x->ups[i - 1];
        x->ups[i] = Up(b.x, a.h * PPOW[1 << (i - 1)] + b.h,
                       b.hrev * PPOW[1 << (i - 1)] + a.hrev);
      }
    }
    ns.push_back(x);
    return x;
  }

 private:
  map<unsigned long long, node> hnodes;
  int ctim;
  void dfs(node v) {
    if (!v) return;
    assert(!hnodes.count(v->sumhrev));
    hnodes[v->sumhrev] = v;
    v->eulerIds.first = ctim++;
    for (int i = 0; i < 26; i++) dfs(v->ne[i]);
    v->eulerIds.second = ctim++;
  }
  fenv_tree euler;
  vector<node> sufarr;
  vector<int> sufpos;
  fenv_tree sufsum;

 public:
  void precalc() {
    ctim = 0;
    hnodes.clear();
    dfs(ns[0]);
    euler = fenv_tree(ctim);
    assert(ns[0]->cnt == 1);
    sufarr = ns;
    sort(sufarr.begin(), sufarr.end(), cmp);
    for (int i = 0; i < ((int)(sufarr).size()); i++) {
      sufarr[i]->sufpos = i;
    }
    sufsum = fenv_tree(((int)(sufarr).size()));
    addCnt(ns[0]);
  }
  void addCnt(node v) {
    euler.add(v->eulerIds.first, 1);
    euler.add(v->eulerIds.second, -1);
    sufsum.add(v->sufpos, 1);
  }
  int getParSum(node v) { return euler.get(v->eulerIds.first); }
  node getHashRev(unsigned long long h) { return hnodes[h]; }
  node getV(int x) { return ns[x]; }
  int getSufStartWith(node t2) {
    int a =
        lower_bound(sufarr.begin(), sufarr.end(), t2, cmp2) - sufarr.begin();
    int b =
        lower_bound(sufarr.begin(), sufarr.end(), t2, cmp3) - sufarr.begin();
    assert(0 <= a && a <= b && b <= ((int)(sufarr).size()));
    return sufsum.get(b - 1) - sufsum.get(a - 1);
  }
};
struct Op {
  int t, v;
  char c;
};
int main() {
  PPOW[0] = 1;
  for (int i = 1; i <= MAXN; i++) PPOW[i] = PPOW[i - 1] * P;
  int n;
  while (scanf("%d", &n) >= 1) {
    Tree t1, t2;
    long long ans = 1;
    vector<Op> ops(n);
    for (int step = 0; step < n; step++) {
      Op &o = ops[step];
      scanf("%d%d %c", &o.t, &o.v, &o.c), o.v--;
      if (o.t == 1) {
        t1.add(o.v, o.c);
      } else {
        t2.add(o.v, o.c);
      }
    }
    t1.precalc();
    t2.precalc();
    int m1 = 0, m2 = 0;
    for (int step = 0; step < n; step++) {
      Op &o = ops[step];
      if (o.t == 1) {
        node x = t1.getV(++m1);
        t1.addCnt(x);
        ans += t2.getSufStartWith(x);
      } else if (o.t == 2) {
        node x = t2.getV(++m2);
        t2.addCnt(x);
        node y = x;
        unsigned long long ch = 0;
        for (int i = K - 1; i >= 0; i--) {
          unsigned long long h = ch * PPOW[1 << i] + y->ups[i].h;
          if (t1.getHashRev(h)) {
            ch = h;
            y = y->ups[i].x;
          }
        }
        ans += t1.getParSum(t1.getHashRev(ch));
      }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
