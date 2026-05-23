#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, k;
long long dp[18][maxn];
int a[maxn];
struct node {
  int l, r;
  long long sum;
  int size() { return r - l; }
  int unity(int _l, int _r) { return max(0, min(r, _r) - max(l, _l)); }
  node(int _l = 0, int _r = 0) {
    l = _l;
    r = _r;
    sum = 0;
  }
} seg[maxn * 4];
void build(int v, int l, int r) {
  seg[v] = node(l, r);
  if (r - l == 1) return;
  int med = (r + l) / 2;
  build(v * 2, l, med);
  build(v * 2 + 1, med, r);
}
long long get(int v, int l, int r) {
  if (!seg[v].unity(l, r)) return 0;
  if (seg[v].size() == seg[v].unity(l, r)) return seg[v].sum;
  return get(v * 2, l, r) + get(v * 2 + 1, l, r);
}
void change(int v, int ind, long long val) {
  if (seg[v].unity(ind, ind + 1) == 0) return;
  if (seg[v].size() == 1) {
    seg[v].sum = val;
    return;
  }
  change(v * 2, ind, val);
  change(v * 2 + 1, ind, val);
  seg[v].sum = seg[v * 2].sum + seg[v * 2 + 1].sum;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  k++;
  build(1, 0, n);
  vector<int> uq(n);
  iota(uq.begin(), uq.end(), 0);
  sort(uq.begin(), uq.end(), [](int i, int j) { return a[i] < a[j]; });
  for (int i = 0; i < n; i++) dp[1][i] = 1;
  for (int ks = 2; ks <= k; ks++) {
    for (int i = 0; i < n; i++) change(1, i, 0);
    for (int i : uq) {
      dp[ks][i] = get(1, 0, i);
      change(1, i, dp[ks - 1][i]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) ans += dp[k][i];
  cout << ans << endl;
}
