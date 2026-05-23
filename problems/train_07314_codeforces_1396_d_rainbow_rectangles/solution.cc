#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int mo = 1000000007;
int n, K, L, ans;
int x[N], y[N], v[N];
int qx[N], qy[N], py[N];
vector<pair<int, int> > op[N];
pair<int, int> opp[N];
int pl[N], pr[N], q[N];
struct node {
  int X, Y, v;
} opt[N * 4];
int mx[N * 4], smx[N * 4];
int mxs[N * 4], sum[N * 4];
void build(int k, int l, int r) {
  mx[k] = 1 << 30;
  smx[k] = -(1 << 30);
  mxs[k] = qy[r + 1] - qy[l];
  sum[k] = 1ll * mx[k] * mxs[k] % mo;
  if (l == r) return;
  int mid = (l + r) / 2;
  build(k * 2, l, mid);
  build(k * 2 + 1, mid + 1, r);
}
void UPD(int k, int v) {
  sum[k] = (sum[k] + 1ll * (v + mo - mx[k]) * mxs[k] % mo) % mo;
  mx[k] = v;
}
void pushdown(int k) {
  if (mx[k * 2] > mx[k]) UPD(k * 2, mx[k]);
  if (mx[k * 2 + 1] > mx[k]) UPD(k * 2 + 1, mx[k]);
}
void pushup(int k) {
  mx[k] = max(mx[k * 2], mx[k * 2 + 1]);
  smx[k] = max((mx[k * 2] == mx[k] ? smx[k * 2] : mx[k * 2]),
               mx[k * 2 + 1] == mx[k] ? smx[k * 2 + 1] : mx[k * 2 + 1]);
  mxs[k] = (mx[k * 2] == mx[k] ? mxs[k * 2] : 0) +
           (mx[k * 2 + 1] == mx[k] ? mxs[k * 2 + 1] : 0);
  sum[k] = (sum[k * 2] + sum[k * 2 + 1]) % mo;
}
void change(int k, int l, int r, int x, int y, int v) {
  if (x <= l && r <= y) {
    if (mx[k] <= v) return;
    if (smx[k] < v) return UPD(k, v);
  }
  pushdown(k);
  int mid = (l + r) / 2;
  if (x <= mid) change(k * 2, l, mid, x, y, v);
  if (y > mid) change(k * 2 + 1, mid + 1, r, x, y, v);
  pushup(k);
}
bool cmp(node a, node b) { return a.X < b.X; }
int Func(int p) {
  int top = 0;
  for (int i = (int)(1); i <= (int)(K); i++) op[i].resize(0);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (x[i] >= p) op[v[i]].push_back(pair<int, int>(py[i], x[i]));
  for (int i = (int)(1); i <= (int)(K); i++) {
    if (!op[i].size()) return 0;
    sort(op[i].begin(), op[i].end());
    int m = 0, t;
    for (auto j : op[i])
      if (!m || opp[m].first != j.first) opp[++m] = j;
    for (int j = (int)(1); j <= (int)(m); j++) pl[j] = 1, pr[j] = *qy;
    t = 0;
    for (int j = (int)(1); j <= (int)(m); j++) {
      for (; t && opp[q[t]].second > opp[j].second; --t)
        pr[q[t]] = opp[j].first;
      if (t) pl[j] = opp[q[t]].first;
      q[++t] = j;
    }
    opp[0] = pair<int, int>(1, 0);
    opp[m + 1] = pair<int, int>(*qy, 0);
    for (int j = (int)(1); j <= (int)(m); j++)
      opt[++top] = (node){pl[j], pr[j], L - opp[j].second};
    for (int j = (int)(1); j <= (int)(m + 1); j++)
      opt[++top] = (node){opp[j - 1].first, opp[j].first, 0};
  }
  sort(opt + 1, opt + top + 1, cmp);
  long long res = 0;
  int pos = 1;
  build(1, 1, (*qy) - 1);
  for (int i = (int)(1); i <= (int)((*qy) - 1); i++) {
    for (; pos <= top && opt[pos].X <= i; ++pos)
      change(1, 1, (*qy) - 1, 1, opt[pos].Y - 1, opt[pos].v);
    change(1, 1, (*qy) - 1, 1, i, 0);
    res = (res + 1ll * (qy[i + 1] - qy[i]) * sum[1]) % mo;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &K, &L);
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%d%d%d", &x[i], &y[i], &v[i]);
  for (int i = (int)(1); i <= (int)(n); i++) qx[++*qx] = x[i], qy[++*qy] = y[i];
  qy[++*qy] = -1;
  qy[++*qy] = L;
  qx[++*qx] = -1;
  sort(qx + 1, qx + *qx + 1);
  sort(qy + 1, qy + *qy + 1);
  *qx = unique(qx + 1, qx + *qx + 1) - qx - 1;
  *qy = unique(qy + 1, qy + *qy + 1) - qy - 1;
  for (int i = (int)(1); i <= (int)(n); i++)
    py[i] = lower_bound(qy + 1, qy + *qy + 1, y[i]) - qy;
  for (int i = (int)(2); i <= (int)(*qx); i++)
    ans = (ans + 1ll * (qx[i] - qx[i - 1]) * Func(qx[i])) % mo;
  cout << (ans + mo) % mo << endl;
}
