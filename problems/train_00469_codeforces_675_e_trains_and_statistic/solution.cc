#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 100;
vector<int> tr(4 * maxn), a(maxn);
void upd(int idx) {
  int l = idx * 2, r = idx * 2 + 1;
  if (tr[l] == -1 || tr[r] == -1) {
    tr[idx] = max(tr[l], tr[r]);
  } else {
    (a[tr[l]] >= a[tr[r]] ? tr[idx] = tr[l] : tr[idx] = tr[r]);
  }
}
void build(int idx, int l, int r) {
  if (l == r) {
    tr[idx] = l;
    return;
  }
  int m = (l + r) >> 1;
  build(idx * 2, l, m);
  build(idx * 2 + 1, m + 1, r);
  upd(idx);
}
int get(int idx, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) {
    return tr[idx];
  }
  if (ll > r || rr < l) {
    return -1;
  }
  int m = (l + r) >> 1;
  int fi = get(idx * 2, l, m, ll, rr);
  int se = get(idx * 2 + 1, m + 1, r, ll, rr);
  if (fi == -1) {
    return se;
  }
  if (se == -1) {
    return fi;
  }
  return (a[fi] >= a[se] ? fi : se);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d", &a[i]);
  }
  a[n] = 0;
  build(1, 1, n);
  vector<long long> dp(n + 10, 0);
  long long ans = 0;
  for (int i = n - 1; i > 0; i--) {
    int idx = get(1, 1, n, i + 1, a[i]);
    dp[i] = dp[idx] + n - i - (a[i] - idx);
    ans += dp[i];
  }
  printf("%lld\n", ans);
  return 0;
}
