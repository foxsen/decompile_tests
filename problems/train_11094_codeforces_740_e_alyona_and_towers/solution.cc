#include <bits/stdc++.h>
using namespace std;
struct four {
  int a, b, c, d;
  four(int a_ = 0, int b_ = 0, int c_ = 0, int d_ = 0) {
    a = a_;
    b = b_;
    c = c_;
    d = d_;
  }
  int f() { return d - a; }
};
bool operator<(const four& f, const four& g) { return (f.a < g.a); }
int n, m;
vector<long long> a, b, l, r, d;
map<int, int> ma;
set<four> se;
four el, er;
four take_seg(int i) {
  four f = *(--se.upper_bound(four(i)));
  se.erase(f);
  if (!(--ma[f.f()])) ma.erase(f.f());
  return f;
}
void push_seg(four f) {
  if (f.f()) {
    se.insert(f);
    ++ma[f.f()];
  }
}
void neg_zer(int i) {
  el = er = take_seg(i);
  el.d = i;
  er.a = er.b = er.c = i + 1;
  push_seg(el);
  push_seg(er);
}
void pos_zer(int i) {
  el = er = take_seg(i);
  el.b = el.c = el.d = i;
  er.a = i + 1;
  push_seg(el);
  push_seg(er);
}
void zer_neg(int i) {
  el = four(i, i, i, i + 1);
  if (i > 0 && b[i - 1] != 0) {
    el = take_seg(i - 1);
    ++el.d;
  }
  if (i < n - 2 && b[i + 1] < 0) el.d = (take_seg(i + 1)).d;
  push_seg(el);
}
void zer_pos(int i) {
  el = four(i, i + 1, i + 1, i + 1);
  if (i < n - 2 && b[i + 1] != 0) {
    el = take_seg(i + 1);
    --el.a;
  }
  if (i > 0 && b[i - 1] > 0) el.a = (take_seg(i - 1)).a;
  push_seg(el);
}
void add(int i, long long x) {
  if (b[i] == 0) zer_pos(i);
  if (b[i] < 0 && b[i] + x >= 0) neg_zer(i);
  if (b[i] < 0 && b[i] + x > 0) zer_pos(i);
  b[i] += x;
}
void rem(int i, long long x) {
  if (b[i] == 0) zer_neg(i);
  if (b[i] > 0 && b[i] - x <= 0) pos_zer(i);
  if (b[i] > 0 && b[i] - x < 0) zer_neg(i);
  b[i] -= x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> m;
  l.resize(m);
  r.resize(m);
  d.resize(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i] >> d[i];
    --l[i];
    --r[i];
  }
  b.assign(n - 1, 0);
  for (int i = 0; i < n - 1; ++i) {
    long long dif = a[i + 1] - a[i];
    if (dif > 0) add(i, dif);
    if (dif < 0) rem(i, -dif);
  }
  ++ma[0];
  for (int i = 0; i < m; ++i) {
    if (l[i] > 0) add(--l[i], d[i]);
    if (r[i] < n - 1) rem(r[i], d[i]);
    cout << (--ma.end())->first + 1 << "\n";
  }
  return 0;
}
