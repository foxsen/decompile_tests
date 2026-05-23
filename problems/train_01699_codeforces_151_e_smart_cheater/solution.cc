#include <bits/stdc++.h>
using namespace std;
namespace Solve {
const int MAX_N = 150000, MAX_M = 300000;
int n, m, c;
int x[MAX_N + 1], p[MAX_N + 1];
double v[MAX_N + 1];
const int MAX_R = 1 << 18;
int h, sz;
struct node_t {
  double v, lv, rv, s;
  node_t() { v = lv = rv = s = 0.0; }
} node[MAX_R << 1];
node_t operator+(const node_t &a, const node_t &b) {
  node_t ret;
  ret.s = a.s + b.s;
  ret.lv = a.lv;
  if (fabs(a.lv - a.s) < 1E-8) ret.lv += b.lv;
  ret.lv = max(ret.lv, a.s + b.lv);
  ret.rv = b.rv;
  if (fabs(b.rv - b.s) < 1E-8) ret.rv += a.rv;
  ret.rv = max(ret.rv, b.s + a.rv);
  ret.v = max(max(a.v, b.v), a.rv + b.lv);
  return ret;
}
void init(int x) {
  int t = ((x & (x + 1)) == 0) ? x + 1 : x;
  while (t >>= 1) h++;
  sz = 1 << (h + 1);
  for (int i = 1; i <= x; i++)
    node[i + sz].s = v[i], node[i + sz].v = max(0.0, v[i]),
             node[i + sz].lv = node[i + sz].rv = node[i + sz].v;
  for (int i = sz - 1; i; i--)
    node[i] = node[((i) << 1)] + node[((i) << 1 | 1)];
}
node_t ask_on_range(int l, int r) {
  l += sz - 1, r += sz + 1;
  node_t la, ra;
  for (; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (~l & 1) la = la + node[l ^ 1];
    if (r & 1) ra = node[r ^ 1] + ra;
  }
  return (la + ra);
}
void solve(FILE *fin, FILE *fout) {
  fscanf(fin, "%d%d%d", &n, &m, &c);
  for (int i = 1; i <= n; i++) fscanf(fin, "%d", &x[i]);
  for (int i = 1; i < n; i++) {
    fscanf(fin, "%d", &p[i]);
    v[i] = (x[i + 1] - x[i]) * 0.5 - (p[i] / 100.0) * c;
  }
  init(n - 1);
  double ans = 0.0;
  for (int i = 1; i <= m; i++) {
    int a, b;
    fscanf(fin, "%d%d", &a, &b);
    ans += ask_on_range(a, b - 1).v;
  }
  fprintf(fout, "%.8lf\n", ans);
}
}  // namespace Solve
int main() {
  Solve::solve(stdin, stdout);
  return 0;
}
