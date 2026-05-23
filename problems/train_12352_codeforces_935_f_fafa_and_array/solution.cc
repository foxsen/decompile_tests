#include <bits/stdc++.h>
using namespace std;
vector<long long int> diff;
struct iii {
  long long int d, e, f;
};
iii comb(iii const& a, iii const& b) {
  return {max(a.d, b.d), max(a.e, b.e), max(a.f, b.f)};
}
vector<iii> st;
void build(int idx, int l, int r) {
  if (l + 1 == r) {
    long long int d1 = -diff[l - 1], d2 = diff[l], t = abs(d1) + abs(d2);
    st[idx] = {d1 + d2 - t, max(d1, d2) - min(d1, d2) - t, -d1 - d2 - t};
    return;
  }
  int m = l + (r - l) / 2;
  build(2 * idx + 1, l, m);
  build(2 * idx + 2, m, r);
  st[idx] = comb(st[2 * idx + 1], st[2 * idx + 2]);
}
iii query(int idx, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return st[idx];
  if (r <= ql || qr <= l) return {LLONG_MIN, LLONG_MIN, LLONG_MIN};
  int m = l + (r - l) / 2;
  iii lv = query(2 * idx + 1, l, m, ql, qr);
  iii rv = query(2 * idx + 2, m, r, ql, qr);
  return comb(lv, rv);
}
void update(int idx, int l, int r, int ui) {
  if (ui <= l && r <= ui + 1) {
    long long int d1 = -diff[l - 1], d2 = diff[l], t = abs(d1) + abs(d2);
    st[idx] = {d1 + d2 - t, max(d1, d2) - min(d1, d2) - t, -d1 - d2 - t};
    return;
  }
  if (r <= ui || ui < l) return;
  int m = l + (r - l) / 2;
  update(2 * idx + 1, l, m, ui);
  update(2 * idx + 2, m, r, ui);
  st[idx] = comb(st[2 * idx + 1], st[2 * idx + 2]);
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int q;
  cin >> q;
  diff.assign(n - 1, 0);
  long long int sum = 0;
  for (int i = 0; i < n - 1; ++i)
    diff[i] = a[i + 1] - a[i], sum += abs(diff[i]);
  st.assign(4 * n, iii());
  build(0, 1, n - 1);
  while (q--) {
    int t, l, r;
    long long int x;
    cin >> t >> l >> r >> x;
    l--, r--;
    if (t == 1) {
      iii q = query(0, 1, n - 1, l, r + 1);
      long long int res = sum + max({-2 * x + q.d, q.e, 2 * x + q.f});
      cout << res << endl;
    } else {
      sum -= abs(diff[l - 1]), diff[l - 1] += x, sum += abs(diff[l - 1]);
      sum -= abs(diff[r]), diff[r] -= x, sum += abs(diff[r]);
      update(0, 1, n - 1, l - 1);
      update(0, 1, n - 1, l);
      update(0, 1, n - 1, r);
      update(0, 1, n - 1, r + 1);
    }
  }
}
