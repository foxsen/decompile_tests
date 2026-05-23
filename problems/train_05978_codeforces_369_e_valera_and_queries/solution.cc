#include <bits/stdc++.h>
using namespace std;
long long pw(long long base, long long e) {
  return e ? pw(base * base, e / 2) * (e % 2 ? base : 1) : 1;
}
const int maxn = 3e5 + 10, mod = 1e9 + 7, maxlg = 21;
const long long INF = 1e9;
long long seg[maxlg][maxn];
int n;
pair<int, int> a[maxn];
int get(int lx, int rx, int l, int r, int x, int val) {
  if (lx >= l && rx <= r) {
    int i = (int)log2(x);
    return rx - (lower_bound(seg[i] + lx, seg[i] + rx, val) - seg[i]);
  }
  if (lx >= r || rx <= l) {
    return 0;
  }
  int mid = (lx + rx) / 2;
  return get(lx, mid, l, r, 2 * x, val) + get(mid, rx, l, r, 2 * x + 1, val);
}
void build(int ind, int l, int r) {
  if (l == r - 1) {
    int i = (int)log2(ind);
    seg[i][l] = a[l].second;
    return;
  }
  int mid = (l + r) / 2;
  build(ind * 2, l, mid);
  build(ind * 2 + 1, mid, r);
  int i0, i1, i2;
  i1 = (int)log2(ind * 2);
  i2 = (int)log2(ind * 2 + 1);
  i0 = (int)log2(ind);
  merge(seg[i1] + l, seg[i1] + mid, seg[i2] + mid, seg[i2] + r, seg[i0] + l);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q, cnt, m;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + n);
  int b[n];
  int c[n];
  for (int i = 0; i < n; i++) {
    b[i] = a[i].second;
    c[i] = a[i].first;
  }
  build(1, 0, n);
  while (q--) {
    cin >> m;
    int ans = 0;
    int prev, cur;
    prev = cur = 0;
    int l, r;
    for (int i = 0; i < m; i++) {
      cin >> cur;
      l = upper_bound(c, c + n, prev) - c;
      r = upper_bound(c, c + n, cur) - c - 1;
      r++;
      ans += get(0, n, l, r, 1, cur);
      prev = cur;
    }
    cout << ans << '\n';
  }
}
