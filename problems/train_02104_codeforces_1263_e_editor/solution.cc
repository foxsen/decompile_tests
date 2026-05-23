#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
int dat[maxn];
int minv[maxn << 2];
int maxv[maxn << 2];
int addv[maxn << 2];
char s[maxn];
void inline pushdown(int o) {
  if (!addv[o]) return;
  addv[(o << 1)] += addv[o];
  addv[(o << 1 | 1)] += addv[o];
  minv[(o << 1)] += addv[o];
  minv[(o << 1 | 1)] += addv[o];
  maxv[(o << 1)] += addv[o];
  maxv[(o << 1 | 1)] += addv[o];
  addv[o] = 0;
}
void inline pushup(int o) {
  minv[o] = min(minv[(o << 1)], minv[(o << 1 | 1)]);
  maxv[o] = max(maxv[(o << 1)], maxv[(o << 1 | 1)]);
}
void inline build(int o, int l, int r) {
  addv[o] = 0;
  if (l == r) {
    minv[o] = dat[l];
    maxv[o] = dat[l];
    return;
  }
  int mid = (l + r) >> 1;
  build((o << 1), l, mid);
  build((o << 1 | 1), mid + 1, r);
  pushup(o);
}
void inline change(int o, int l, int r, int ql, int qr, int v) {
  if (ql <= l && qr >= r) {
    minv[o] += v;
    maxv[o] += v;
    addv[o] += v;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(o);
  if (ql <= mid) change((o << 1), l, mid, ql, qr, v);
  if (qr > mid) change((o << 1 | 1), mid + 1, r, ql, qr, v);
  pushup(o);
}
int inline query_min(int o, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) return minv[o];
  int mid = (l + r) >> 1;
  int ans = 0x3f3f3f3f;
  pushdown(o);
  if (ql <= mid) ans = min(ans, query_min((o << 1), l, mid, ql, qr));
  if (qr > mid) ans = min(ans, query_min((o << 1 | 1), mid + 1, r, ql, qr));
  return ans;
}
int inline query_max(int o, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) return maxv[o];
  int mid = (l + r) >> 1;
  int ans = -1;
  pushdown(o);
  if (ql <= mid) ans = max(ans, query_max((o << 1), l, mid, ql, qr));
  if (qr > mid) ans = max(ans, query_max((o << 1 | 1), mid + 1, r, ql, qr));
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  build(1, 1, n);
  string a;
  cin >> a;
  int pos = 0;
  long long sum = 0;
  for (int i = 0; i < a.size(); i++) {
    int q = 0;
    if (a[i] == '(')
      q++;
    else if (a[i] == ')')
      q--;
    if (s[pos] == '(')
      q--;
    else if (s[pos] == ')')
      q++;
    if (a[i] == 'R')
      pos++;
    else if (a[i] == 'L')
      pos = max(pos - 1, 0);
    else {
      s[pos] = a[i];
      if (q) change(1, 1, n, pos + 1, n, q);
      sum += q;
    }
    if (sum != 0 || query_min(1, 1, n, 1, n) != 0)
      cout << "-1 ";
    else
      cout << query_max(1, 1, n, 1, n) << " ";
  }
}
