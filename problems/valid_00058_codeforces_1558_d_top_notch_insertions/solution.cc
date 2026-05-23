#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int MAXN = 4e5 + 1;
int quick(int A, int B) {
  if (B == 0) return 1;
  int tmp = quick(A, B >> 1);
  tmp = 1ll * tmp * tmp % MOD;
  if (B & 1) tmp = 1ll * tmp * A % MOD;
  return tmp;
}
int inv(int A) { return quick(A, MOD - 2); }
int fact[MAXN], ifact[MAXN];
int comb(int A, int B) {
  return 1ll * fact[A] * ifact[B] % MOD * ifact[A - B] % MOD;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<pair<int, int> > gt;
struct Treap {
  int root = 0;
  struct node {
    pair<int, int> val;
    int ran, l, r, siz;
  };
  vector<node> v;
  int new_node(pair<int, int> val) {
    if (v.empty()) {
      v.push_back(node{make_pair(0, -1), (int)rng() % INF, 0, 0, 0});
    }
    v.push_back(node{val, (int)rng() % INF, 0, 0, val.second - val.first + 1});
    return v.size() - 1;
  }
  void update(int index) {
    v[index].siz = v[index].val.second - v[index].val.first + 1;
    if (v[index].l) {
      v[index].siz += v[v[index].l].siz;
    }
    if (v[index].r) {
      v[index].siz += v[v[index].r].siz;
    }
  }
  void split_by_size(int base, int& x, int& y, int boundary) {
    if (!boundary) {
      x = 0;
      y = base;
      return;
    }
    if (!base) {
      x = y = 0;
      return;
    }
    if (v[v[base].l].siz + v[base].val.second - v[base].val.first + 1 <
        boundary) {
      x = base;
      split_by_size(v[base].r, v[x].r, y,
                    boundary - v[v[base].l].siz -
                        (v[base].val.second - v[base].val.first + 1));
      update(x);
    } else {
      y = base;
      split_by_size(v[base].l, x, v[y].l, boundary);
      update(y);
    }
  }
  void getleft(int base, int& x, int& y) {
    if (!base) {
      x = y = 0;
      return;
    }
    if (!v[base].l) {
      x = base;
      y = v[base].r;
      v[base].r = 0;
      update(x);
    } else {
      y = base;
      getleft(v[base].l, x, v[y].l);
      update(y);
    }
  }
  int merge(int x, int y) {
    if (x == 0 || y == 0) return x + y;
    if (v[x].ran > v[y].ran) {
      v[x].r = merge(v[x].r, y);
      update(x);
      return x;
    }
    v[y].l = merge(x, v[y].l);
    update(y);
    return y;
  }
  void traval(int now) {
    if (now == 0) return;
    traval(v[now].l);
    gt.push_back(v[now].val);
    traval(v[now].r);
  }
} fhq;
int x[MAXN], y[MAXN];
void solve() {
  fhq.v.clear();
  fhq.root = 0;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  vector<pair<pair<int, int>, int> > can;
  int pre = 0;
  for (int i = 1; i <= m; ++i) {
    if (pre + 1 <= x[i] - 1) {
      can.push_back(make_pair(make_pair(pre + 1, x[i] - 1), n));
    }
    can.push_back(make_pair(make_pair(x[i], x[i]), y[i]));
    pre = x[i];
  }
  for (auto it : can) {
    if (it.second == n) {
      fhq.root = fhq.merge(fhq.root, fhq.new_node(it.first));
    } else {
      int x, y;
      fhq.split_by_size(fhq.root, x, y, it.second);
      int z;
      fhq.getleft(y, z, y);
      int nw = fhq.new_node(it.first);
      it.second -= fhq.v[x].siz;
      int _, __;
      _ = __ = 0;
      it.second--;
      pair<int, int> orz = fhq.v[z].val;
      if (it.second) {
        _ = fhq.new_node(make_pair(orz.first, orz.first + it.second - 1));
      }
      if (it.second != fhq.v[z].siz) {
        __ = fhq.new_node(make_pair(orz.first + it.second, orz.second));
      }
      fhq.root = fhq.merge(x, fhq.merge(fhq.merge(fhq.merge(_, nw), __), y));
    }
  }
  gt.clear();
  fhq.traval(fhq.root);
  int cnt = 0;
  for (int i = 0; i < gt.size(); ++i) {
    if (i) {
      if (gt[i - 1].second > gt[i].first) {
        cnt++;
      }
    }
  }
  int ans = comb(n - 1 + n - 1 - cnt + 1, n);
  printf("%d\n", ans);
}
int main() {
  fact[0] = 1;
  for (int i = 1; i <= 400000; ++i) fact[i] = 1ll * fact[i - 1] * i % MOD;
  for (int i = 0; i <= 400000; ++i) ifact[i] = inv(fact[i]);
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
