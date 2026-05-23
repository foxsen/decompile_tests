#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7, N = 1e5 + 7;
int n, m, x;
struct T {
  long long ans;
  vector<pair<int, int> > l, r;
  T() {}
  T(int val) {
    l = r = {{val, 1}};
    ans = val >= x;
  }
};
vector<pair<int, int> > cmb(vector<pair<int, int> > a,
                            vector<pair<int, int> > b) {
  assert(a.size());
  for (pair<int, int> p : b) {
    if ((p.first | a.back().first) == a.back().first)
      a.back().second += p.second;
    else
      a.emplace_back(p.first | a.back().first, p.second);
  }
  return a;
}
T operator+(const T a, const T b) {
  T c;
  c.ans = a.ans + b.ans;
  c.l = cmb(a.l, b.l);
  c.r = cmb(b.r, a.r);
  long long sum = 0;
  for (int i = 0, j = (int)b.l.size() - 1; i < a.r.size(); i++) {
    while (j >= 0 && (b.l[j].first | a.r[i].first) >= x)
      sum += b.l[j].second, j--;
    c.ans += sum * a.r[i].second;
  }
  return c;
}
T t[N * 4];
int a[N];
void build(int v = 1, int tl = 0, int tr = n) {
  if (tr - tl == 1) {
    t[v] = T(a[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2, tl, tm);
  build(v * 2 + 1, tm, tr);
  t[v] = t[v * 2] + t[v * 2 + 1];
}
void upd(int pos, int val, int v = 1, int tl = 0, int tr = n) {
  if (tr - tl == 1) {
    t[v] = T(val);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm)
    upd(pos, val, v * 2, tl, tm);
  else
    upd(pos, val, v * 2 + 1, tm, tr);
  t[v] = t[v * 2] + t[v * 2 + 1];
}
T qry(int l, int r, int v = 1, int tl = 0, int tr = n) {
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  if (r <= tm)
    return qry(l, r, v * 2, tl, tm);
  else if (l >= tm)
    return qry(l, r, v * 2 + 1, tm, tr);
  else
    return qry(l, r, v * 2, tl, tm) + qry(l, r, v * 2 + 1, tm, tr);
}
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  ;
  cin >> n >> m >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, y;
      cin >> i >> y;
      upd(i - 1, y);
    } else {
      int l, r;
      cin >> l >> r;
      cout << qry(l - 1, r).ans << endl;
    }
  }
}
