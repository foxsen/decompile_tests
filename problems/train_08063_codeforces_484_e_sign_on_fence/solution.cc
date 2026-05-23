#include <bits/stdc++.h>
using namespace std;
struct event {
  int y, i, type;
  event() {}
  event(int y, int i, int type) : y(y), i(i), type(type) {}
  bool operator<(const event &e) const {
    if (y != e.y) return y > e.y;
    return type < e.type;
  }
};
struct seg {
  int mx, l, r, f;
  seg() {}
  seg(int mx, int l, int r, int f) : mx(mx), l(l), r(r), f(f) {}
};
int n, h[100010], m;
int ql[100010], qr[100010], qw[100010];
int lo[100010], hi[100010];
vector<event> e;
seg s[4 * 100010];
seg merge(seg &l, seg &r) {
  int mx = max(max(l.mx, r.mx), l.r + r.l);
  int ll = l.l + (l.f ? r.l : 0);
  int rr = r.r + (r.f ? l.r : 0);
  int ff = l.f && r.f;
  return seg(mx, ll, rr, ff);
}
void update(int i, int l, int r, int pos) {
  if (l > pos || r < pos) return;
  if (l == r) {
    s[i].mx = s[i].l = s[i].r = s[i].f = 1;
    return;
  }
  int mid = (l + r) / 2;
  update(2 * i, l, mid, pos);
  update(2 * i + 1, mid + 1, r, pos);
  s[i] = merge(s[2 * i], s[2 * i + 1]);
}
seg query(int i, int l, int r, int ll, int rr) {
  if (l > rr || r < ll) return seg();
  if (l >= ll && r <= rr) return s[i];
  int mid = (l + r) / 2;
  seg sl = query(2 * i, l, mid, ll, rr);
  seg sr = query(2 * i + 1, mid + 1, r, ll, rr);
  if (mid < ll) return sr;
  if (mid >= rr) return sl;
  return merge(sl, sr);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", h + i);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", ql + i, qr + i, qw + i);
    hi[i] = 1000000005;
  }
  while (1) {
    e.clear();
    for (int i = 1; i <= n; i++) e.push_back(event(h[i], i, 0));
    bool done = 1;
    for (int i = 1; i <= m; i++) {
      if (hi[i] - lo[i] > 1) {
        done = 0;
        e.push_back(event((lo[i] + hi[i]) / 2, i, 1));
      }
    }
    if (done) break;
    sort(e.begin(), e.end());
    memset(s, 0, sizeof(s));
    for (int i = 0; i < e.size(); i++) {
      if (e[i].type == 0) {
        update(1, 1, n, e[i].i);
      } else {
        int l = ql[e[i].i];
        int r = qr[e[i].i];
        if (query(1, 1, n, l, r).mx >= qw[e[i].i])
          lo[e[i].i] = e[i].y;
        else
          hi[e[i].i] = e[i].y;
      }
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", lo[i]);
}
