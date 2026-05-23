#include <bits/stdc++.h>
using namespace std;
long long a, b, c, q, w, e, o, h[200001], qq[200001], ww[200001], ee[200001],
    v[200001], di[200001], fa[200001][21], de[200001], lg[200001], y[200001],
    po[200001], cn, di1[200001];
struct p {
  long long q, w, e;
} l[400001], ll[400001];
struct pp {
  long long q, w;
  bool operator<(const pp& qq) const { return w > qq.w; }
};
struct ppp {
  long long l, r, mn, ta;
} g[1600001];
priority_queue<pp> qu;
void diji() {
  memset(v, 0, sizeof(v));
  memset(di, 0x3f3f3f3f3f, sizeof(di));
  di[1] = 0;
  qu.push(pp{1, 0});
  while (!qu.empty()) {
    pp r = qu.top();
    qu.pop();
    if (v[r.q]) continue;
    v[r.q] = 1;
    for (int i = h[r.q]; i; i = l[i].w) {
      if (di[l[i].q] > di[r.q] + l[i].e) {
        di[l[i].q] = di[r.q] + l[i].e;
        fa[l[i].q][0] = r.q;
        if (!v[l[i].q]) {
          qu.push(pp{l[i].q, di[l[i].q]});
        }
      }
    }
  }
  memset(v, 0, sizeof(v));
  memset(di1, 0x3f3f3f3f3f, sizeof(di1));
  di1[a] = 0;
  qu.push(pp{a, 0});
  while (!qu.empty()) {
    pp r = qu.top();
    qu.pop();
    if (v[r.q]) continue;
    v[r.q] = 1;
    for (int i = h[r.q]; i; i = l[i].w) {
      if (di1[l[i].q] > di1[r.q] + l[i].e) {
        di1[l[i].q] = di1[r.q] + l[i].e;
        if (!v[l[i].q]) {
          qu.push(pp{l[i].q, di1[l[i].q]});
        }
      }
    }
  }
}
void dfs(long long qq, long long ww, long long ee) {
  y[ee] = qq;
  if (qq == a) {
    for (int i = 1; i <= ee; i++) {
      po[y[i]] = i;
    }
    cn = ee;
  }
  fa[qq][0] = ww;
  for (int i = 1; i <= 20; i++) {
    fa[qq][i] = fa[fa[qq][i - 1]][i - 1];
  }
  de[qq] = de[ww] + 1;
  for (int i = h[qq]; i; i = l[i].w) {
    if (l[i].q != ww) {
      dfs(l[i].q, qq, ee + 1);
    }
  }
}
long long LCA(long long qq, long long ww) {
  if (de[qq] < de[ww]) swap(qq, ww);
  while (de[qq] > de[ww]) {
    qq = fa[qq][lg[de[qq] - de[ww]] - 1];
  }
  if (qq == ww) return qq;
  for (int i = 20; i >= 0; i--) {
    if (fa[qq][i] != fa[ww][i]) {
      qq = fa[qq][i];
      ww = fa[ww][i];
    }
  }
  return fa[qq][0];
}
void pushdown(long long qq) {
  if (g[qq].ta <= 10000000000000000) {
    g[qq << 1].mn = min(g[qq << 1].mn, g[qq].ta);
    g[qq << 1].ta = min(g[qq << 1].ta, g[qq].ta);
    g[qq << 1 | 1].mn = min(g[qq << 1 | 1].mn, g[qq].ta);
    g[qq << 1 | 1].ta = min(g[qq].ta, g[qq << 1 | 1].ta);
    g[qq].ta = 10000000000000000;
  }
}
void pushup(long long qq) { g[qq].mn = min(g[qq << 1].mn, g[qq << 1 | 1].mn); }
void build(long long x, long long ll, long long rr) {
  g[x].l = ll;
  g[x].r = rr;
  g[x].ta = 10000000000000000;
  g[x].mn = 10000000000000000;
  if (ll == rr) {
    return;
  }
  long long mid = ((ll + rr) >> 1);
  build(x << 1, ll, mid);
  build(x << 1 | 1, mid + 1, rr);
  pushup(x);
}
void change(long long x, long long ll, long long rr, long long qq, long long ww,
            long long ee) {
  if (ll > rr || qq > ww) return;
  pushdown(x);
  if (qq <= ll && rr <= ww) {
    g[x].mn = min(g[x].mn, ee);
    g[x].ta = min(g[x].ta, ee);
    return;
  }
  long long mid = ((ll + rr) >> 1);
  if (mid >= ww) {
    change(x << 1, ll, mid, qq, ww, ee);
  } else if (mid < qq) {
    change(x << 1 | 1, mid + 1, rr, qq, ww, ee);
  } else {
    change(x << 1, ll, mid, qq, ww, ee);
    change(x << 1 | 1, mid + 1, rr, qq, ww, ee);
  }
  pushup(x);
}
long long query(long long x, long long ll, long long rr, long long qq,
                long long ww) {
  if (ll > rr || qq > ww) return 0x3f3f3f3f3f;
  pushdown(x);
  if (qq <= ll && rr <= ww) {
    return g[x].mn;
  }
  long long mid = ((ll + rr) >> 1);
  if (mid >= ww) {
    return query(x << 1, ll, mid, qq, ww);
  } else if (mid < qq) {
    return query(x << 1 | 1, mid + 1, rr, qq, ww);
  } else {
    return min(query(x << 1, ll, mid, qq, ww),
               query(x << 1 | 1, mid + 1, rr, qq, ww));
  }
}
bool ontree(long long qq, long long ww, long long ee) {
  if ((fa[qq][0] == ww || fa[ww][0] == qq) &&
      (di[qq] == di[ww] + ee || di[ww] == di[qq] + ee)) {
    return 1;
  }
  return 0;
}
int main() {
  scanf("%lld%lld%lld", &a, &b, &c);
  bool debug = (c == 67);
  for (int i = 1; i <= a; i++) {
    lg[i] = lg[i - 1] + ((1 << lg[i - 1]) == i);
  }
  for (int i = 1; i <= b; i++) {
    scanf("%lld%lld%lld", &qq[i], &ww[i], &ee[i]);
    q = qq[i];
    w = ww[i];
    e = ee[i];
    o++;
    l[o].q = w;
    l[o].w = h[q];
    h[q] = o;
    l[o].e = e;
    o++;
    l[o].q = q;
    l[o].w = h[w];
    h[w] = o;
    l[o].e = e;
  }
  diji();
  o = 0;
  memset(h, 0, sizeof(h));
  for (int i = 1; i <= a; i++) {
    if (!fa[i][0]) continue;
    q = i;
    w = fa[i][0];
    o++;
    l[o].q = w;
    l[o].w = h[q];
    h[q] = o;
    o++;
    l[o].q = q;
    l[o].w = h[w];
    h[w] = o;
  }
  dfs(1, 0, 1);
  build(1, 1, cn);
  for (int i = 1; i <= b; i++) {
    q = qq[i];
    w = ww[i];
    e = ee[i];
    if (ontree(q, w, e)) continue;
    long long f1 = LCA(q, a), f2 = LCA(w, a);
    long long a1 = po[f1], a2 = po[f2];
    if (a1 > a2) swap(a1, a2);
    a1++;
    change(1, 1, cn, a1, a2, min(e + di[q] + di1[w], e + di[w] + di1[q]));
  }
  for (int i = 1; i <= c; i++) {
    scanf("%lld%lld", &q, &w);
    if (!(po[qq[q]] && po[ww[q]] &&
          (di[qq[q]] == di[ww[q]] + ee[q] || di[ww[q]] == di[qq[q]] + ee[q]))) {
      if (w >= ee[q]) {
        printf("%lld\n", di[a]);
      } else {
        printf("%lld\n", min(di[a], min(di[qq[q]] + w + di1[ww[q]],
                                        di[ww[q]] + w + di1[qq[q]])));
      }
    } else {
      if (w <= ee[q]) {
        printf("%lld\n", di[a] - ee[q] + w);
      } else {
        long long an = di[a] + w - ee[q];
        if (po[qq[q]] > po[ww[q]]) swap(qq[q], ww[q]);
        an = min(an, query(1, 1, cn, po[ww[q]], po[ww[q]]));
        printf("%lld\n", an);
      }
    }
  }
  return 0;
}
