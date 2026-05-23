#include <bits/stdc++.h>
using namespace std;
int a[1 << 18];
int dp[1 << 18], f1[1 << 18], f2[1 << 18], e[1 << 18], c;
char s[1 << 18];
long long d1[1 << 18], d2[1 << 18];
long long st[1 << 18];
void modify(int x, long long v, int p, int lb, int rb) {
  st[p] = ((st[p] + v) % 1145140019);
  if (lb + 1 == rb)
    return;
  else {
    int mid = (lb + rb) >> 1;
    if (x < mid)
      modify(x, v, p << 1, lb, mid);
    else
      modify(x, v, p << 1 | 1, mid, rb);
  }
}
long long query(int l, int r, int p, int lb, int rb) {
  if (l <= lb && rb <= r)
    return st[p];
  else {
    int mid = (lb + rb) >> 1;
    long long res = 0;
    if (l < mid) res = ((res + query(l, r, p << 1, lb, mid)) % 1145140019);
    if (r > mid) res = ((res + query(l, r, p << 1 | 1, mid, rb)) % 1145140019);
    return res;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  c = 0;
  for (int i = 1; i <= n; ++i) {
    int p = lower_bound(dp, dp + c, a[i], less<int>()) - dp;
    if (p == c) c++;
    f1[i] = p + 1;
    dp[p] = a[i];
  }
  m = c;
  vector<vector<int>> v(m + 1);
  for (int i = 1; i <= n; ++i) v[f1[i]].push_back(i);
  for (int j : v[1]) d1[j] = 1;
  for (int i = 2; i <= m; ++i) {
    vector<pair<int, int>> w;
    int n1 = v[i - 1].size(), n2 = v[i].size();
    for (int k : v[i - 1]) w.emplace_back(k, 1);
    for (int k : v[i]) w.emplace_back(k, 2);
    inplace_merge(w.begin(), w.begin() + n1, w.end());
    for (int j = 0; j != n1 + n2; ++j) {
      int k = w[j].first, t = w[j].second;
      if (t == 1)
        modify(a[k], d1[k], 1, 1, 100001);
      else
        d1[k] = query(1, a[k], 1, 1, 100001);
    }
    for (int k : v[i - 1]) modify(a[k], -d1[k], 1, 1, 100001);
  }
  c = 0;
  for (int i = n; i >= 1; --i) {
    int p = lower_bound(dp, dp + c, a[i], greater<int>()) - dp;
    if (p == c) c++;
    f2[i] = p + 1;
    dp[p] = a[i];
  }
  for (int i = 0; i <= m; ++i) v[i].resize(0);
  for (int i = n; i >= 1; --i) v[f2[i]].push_back(i);
  for (int j : v[1]) d2[j] = 1;
  for (int i = 2; i <= m; ++i) {
    vector<pair<int, int>> w;
    int n1 = v[i - 1].size(), n2 = v[i].size();
    for (int k : v[i - 1]) w.emplace_back(k, 1);
    for (int k : v[i]) w.emplace_back(k, 2);
    inplace_merge(w.begin(), w.begin() + n1, w.end(),
                  greater<pair<int, int>>());
    assert(is_sorted(w.begin(), w.end(), greater<pair<int, int>>()));
    for (int j = 0; j != n1 + n2; ++j) {
      int k = w[j].first, t = w[j].second;
      if (t == 1)
        modify(a[k], d2[k], 1, 1, 100001);
      else
        d2[k] = query(a[k] + 1, 100001, 1, 1, 100001);
    }
    for (int k : v[i - 1]) modify(a[k], -d2[k], 1, 1, 100001);
  }
  long long all = 0;
  for (int i = 1; i <= n; ++i) {
    e[i] = ((d1[i] * d2[i]) % 1145140019);
    if (f1[i] == m) all = ((all + d1[i]) % 1145140019);
  }
  for (int i = 1; i <= n; ++i) {
    if (e[i] == 0 || f1[i] + f2[i] - 1 != m)
      s[i] = '1';
    else if (e[i] != all)
      s[i] = '2';
    else
      s[i] = '3';
  }
  s[n + 1] = 0;
  cout << s + 1 << endl;
  return 0;
}
