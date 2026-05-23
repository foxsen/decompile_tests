#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 200010;
const int INF = 0x7fffffff;
class SegTree {
 public:
  SegTree() {}
  void Build(int t, int l, int r) {
    if (l == r) {
      x[t] = sum[t] = ox[l];
      return;
    }
    int mid = (l + r) >> 1;
    Build(t + t, l, mid);
    Build(t + t + 1, mid + 1, r);
    sum[t] = sum[t + t] + sum[t + t + 1];
  }
  void PushDown(int t, int l, int r) {
    if (l == r) return;
    if (x[t] == 0) return;
    x[t + t] += x[t];
    x[t + t + 1] += x[t];
    LL mid = (l + r) >> 1;
    sum[t + t] += (mid - l + 1) * x[t];
    sum[t + t + 1] += (r - mid) * x[t];
    x[t] = 0;
  }
  void Insert(int t, int a, int l, int r, int p, int q) {
    PushDown(t, l, r);
    if (p <= l && r <= q) {
      x[t] += a;
      sum[t] += (r - l + 1LL) * a;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) Insert(t + t, a, l, mid, p, q);
    if (mid + 1 <= q) Insert(t + t + 1, a, mid + 1, r, p, q);
    sum[t] = sum[t + t] + sum[t + t + 1];
  }
  LL Query(int t, int l, int r, int p, int q) {
    PushDown(t, l, r);
    if (p <= l && r <= q) return sum[t];
    int mid = (l + r) >> 1;
    LL ans = 0;
    if (p <= mid) ans += Query(t + t, l, mid, p, q);
    if (mid + 1 <= q) ans += Query(t + t + 1, mid + 1, r, p, q);
    return ans;
  }
  int ox[MAXN];
  LL x[MAXN * 4], sum[MAXN * 4];
} tree;
struct Node {
  int mx, mx2, mn, mn2, cmx, cmn, tmx, tmn, tad;
  LL sum;
};
class SegmentTreeBeats {
 public:
  void Merge(int t) {
    const int lt = t << 1, rt = t << 1 | 1;
    x[t].sum = x[lt].sum + x[rt].sum;
    if (x[lt].mx == x[rt].mx) {
      x[t].mx = x[lt].mx;
      x[t].cmx = x[lt].cmx + x[rt].cmx;
      x[t].mx2 = max(x[lt].mx2, x[rt].mx2);
    } else if (x[lt].mx > x[rt].mx) {
      x[t].mx = x[lt].mx;
      x[t].cmx = x[lt].cmx;
      x[t].mx2 = max(x[lt].mx2, x[rt].mx);
    } else {
      x[t].mx = x[rt].mx;
      x[t].cmx = x[rt].cmx;
      x[t].mx2 = max(x[lt].mx, x[rt].mx2);
    }
    if (x[lt].mn == x[rt].mn) {
      x[t].mn = x[lt].mn;
      x[t].cmn = x[lt].cmn + x[rt].cmn;
      x[t].mn2 = min(x[lt].mn2, x[rt].mn2);
    } else if (x[lt].mn < x[rt].mn) {
      x[t].mn = x[lt].mn;
      x[t].cmn = x[lt].cmn;
      x[t].mn2 = min(x[lt].mn2, x[rt].mn);
    } else {
      x[t].mn = x[rt].mn;
      x[t].cmn = x[rt].cmn;
      x[t].mn2 = min(x[lt].mn, x[rt].mn2);
    }
  }
  void PushAdd(int t, int l, int r, int v) {
    x[t].sum += (r - l + 1LL) * v;
    x[t].mx += v;
    x[t].mn += v;
    if (x[t].mx2 != -INF) x[t].mx2 += v;
    if (x[t].mn2 != INF) x[t].mn2 += v;
    if (x[t].tmx != -INF) x[t].tmx += v;
    if (x[t].tmn != INF) x[t].tmn += v;
    x[t].tad += v;
  }
  void PushMin(int t, int tg) {
    if (x[t].mx <= tg) return;
    x[t].sum += (tg * 1LL - x[t].mx) * x[t].cmx;
    if (x[t].mn2 == x[t].mx) x[t].mn2 = tg;
    if (x[t].mn == x[t].mx) x[t].mn = tg;
    if (x[t].tmx > tg) x[t].tmx = tg;
    x[t].mx = tg;
    x[t].tmn = tg;
  }
  void PushMax(int t, int tg) {
    if (x[t].mn > tg) return;
    x[t].sum += (tg * 1LL - x[t].mn) * x[t].cmn;
    if (x[t].mx2 == x[t].mn) x[t].mx2 = tg;
    if (x[t].mx == x[t].mn) x[t].mx = tg;
    if (x[t].tmn < tg) x[t].tmn = tg;
    x[t].mn = tg;
    x[t].tmx = tg;
  }
  void PushDown(int t, int l, int r) {
    const int lt = t << 1, rt = t << 1 | 1;
    const int mid = (l + r) >> 1;
    if (x[t].tad) {
      PushAdd(lt, l, mid, x[t].tad);
      PushAdd(rt, mid + 1, r, x[t].tad);
    }
    if (x[t].tmx != -INF) {
      PushMax(lt, x[t].tmx);
      PushMax(rt, x[t].tmx);
    }
    if (x[t].tmn != INF) {
      PushMin(lt, x[t].tmn);
      PushMin(rt, x[t].tmn);
    }
    x[t].tad = 0;
    x[t].tmx = -INF;
    x[t].tmn = INF;
  }
  void Build(int t, int l, int r) {
    x[t].tmn = INF;
    x[t].tmx = -INF;
    if (l == r) {
      x[t].sum = x[t].mx = x[t].mn = ox[l];
      x[t].mx2 = -INF;
      x[t].mn2 = INF;
      x[t].cmx = x[t].cmn = 1;
      return;
    }
    int mid = (l + r) >> 1;
    Build(t << 1, l, mid);
    Build(t << 1 | 1, mid + 1, r);
    Merge(t);
  }
  void Add(int t, int l, int r, int L, int R, int v) {
    if (R < l || r < L) return;
    if (L <= l && r <= R) return PushAdd(t, l, r, v);
    int mid = (l + r) >> 1;
    PushDown(t, l, r);
    Add(t << 1, l, mid, L, R, v);
    Add(t << 1 | 1, mid + 1, r, L, R, v);
    Merge(t);
  }
  void SetMin(int t, int l, int r, int L, int R, int v) {
    if (R < l || r < L || x[t].mx <= v) return;
    if (L <= l && r <= R && x[t].mx2 < v) {
      tree.Insert(1, -x[t].cmx, 1, n, v + 1, x[t].mx);
      return PushMin(t, v);
    }
    int mid = (l + r) >> 1;
    PushDown(t, l, r);
    SetMin(t << 1, l, mid, L, R, v);
    SetMin(t << 1 | 1, mid + 1, r, L, R, v);
    Merge(t);
  }
  void SetMax(int t, int l, int r, int L, int R, int v) {
    if (R < l || r < L || x[t].mn >= v) return;
    if (L <= l && r <= R && x[t].mn2 > v) return PushMax(t, v);
    int mid = (l + r) >> 1;
    PushDown(t, l, r);
    SetMax(t << 1, l, mid, L, R, v);
    SetMax(t << 1 | 1, mid + 1, r, L, R, v);
    Merge(t);
  }
  LL QuerySum(int t, int l, int r, int L, int R) {
    if (R < l || r < L) return 0;
    if (L <= l && r <= R) return x[t].sum;
    int mid = (l + r) >> 1;
    PushDown(t, l, r);
    return QuerySum(t << 1, l, mid, L, R) +
           QuerySum(t << 1 | 1, mid + 1, r, L, R);
  }
  LL QueryMax(int t, int l, int r, int L, int R) {
    if (R < l || r < L) return -INF;
    if (L <= l && r <= R) return x[t].mx;
    int mid = (l + r) >> 1;
    PushDown(t, l, r);
    return max(QueryMax(t << 1, l, mid, L, R),
               QueryMax(t << 1 | 1, mid + 1, r, L, R));
  }
  LL QueryMin(int t, int l, int r, int L, int R) {
    if (R < l || r < L) return INF;
    if (L <= l && r <= R) return x[t].mn;
    int mid = (l + r) >> 1;
    PushDown(t, l, r);
    return min(QueryMin(t << 1, l, mid, L, R),
               QueryMin(t << 1 | 1, mid + 1, r, L, R));
  }
  int n;
  int ox[MAXN];
  Node x[MAXN * 4];
} treeb;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  treeb.n = n;
  for (int i = 1; i <= n; ++i) {
    tree.ox[i] = 1;
    treeb.ox[i] = i;
  }
  tree.Build(1, 1, n);
  treeb.Build(1, 1, n);
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      int r = treeb.QueryMax(1, 1, n, a, a);
      if (r > b) {
        tree.Insert(1, -1, 1, n, b + 1, r);
      } else if (r < b) {
        tree.Insert(1, 1, 1, n, r + 1, b);
      }
      if (r != b) {
        treeb.Add(1, 1, n, a, a, b - r);
      }
      if (a == 1) continue;
      treeb.SetMin(1, 1, n, 1, a - 1, a - 1);
    } else {
      cout << tree.Query(1, 1, n, a, b) << "\n";
    }
  }
  return 0;
}
