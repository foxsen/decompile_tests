#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:640000000")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = (int)1e5 + 10;
int n, l, r, ql, qr;
int w[maxn];
long long sum[maxn];
long long solve() {
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + w[i];
  }
  long long res = (long long)1e18;
  int ll = 1;
  int rr = n;
  long long cur = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      res = min(res,
                cur + (sum[rr] - sum[ll - 1]) * l + (rr - ll + 1) * 1LL * ql);
      cur += w[rr] * 1LL * r;
      rr--;
    } else {
      res = min(res,
                cur + (sum[rr] - sum[ll - 1]) * r + (rr - ll + 1) * 1LL * qr);
      cur += w[ll] * 1LL * l;
      ll++;
    }
  }
  res = min(res, cur);
  return res;
}
int main() {
  cin >> n >> l >> r >> ql >> qr;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
  }
  long long res = (long long)1e18;
  res = min(res, solve());
  reverse(w + 1, w + n + 1);
  swap(l, r);
  swap(ql, qr);
  res = min(res, solve());
  cout << res << endl;
  return 0;
}
