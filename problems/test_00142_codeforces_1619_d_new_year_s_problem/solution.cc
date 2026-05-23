#include <bits/stdc++.h>
using namespace std;
double PI = (acos(-1));
long long md = 1000000007;
long long pw(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m);
    m = (m * m);
    b /= 2;
  }
  return c;
}
long long pwmd(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = ((c * m)) % md;
    m = (m * m) % md;
    b /= 2;
  }
  return c;
}
long long modinv(long long n) { return pwmd(n, md - 2); }
long long nc2(long long n) { return (1ll * n * (n - 1)) / 2; }
bool prime(long long a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) return false;
  }
  return true;
}
long long ceel(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
bool cch(long long a, long long b) {
  long double x = a, y = b;
  long double z = 1000000000000000000 / a;
  if (y > z) return 0;
  return 1;
}
void solve() {
  long long m, n;
  cin >> m >> n;
  long long l[m][n];
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) cin >> l[i][j];
  }
  if (n - 1 >= m) {
    vector<long long> ans;
    for (long long i = 0; i < n; i++) {
      long long mx = 0;
      for (long long j = 0; j < m; j++) {
        mx = max(mx, l[j][i]);
      }
      ans.push_back(mx);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << "\n";
    return;
  } else {
    long long x = 1, y = 1000000001;
    while (x + 1 < y) {
      long long mid = (x + y) / 2, flg = 0, gg = 0;
      map<long long, long long> mp;
      for (long long i = 0; i < n; i++) {
        long long zq = 0;
        for (long long j = 0; j < m; j++) {
          if (l[j][i] >= mid) {
            zq = 1;
            if (mp[j]) flg = 1;
            mp[j] = 1;
          }
        }
        if (zq == 0) gg = 1;
      }
      if (flg == 0 || gg) {
        y = mid;
      } else
        x = mid;
    }
    cout << x << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
