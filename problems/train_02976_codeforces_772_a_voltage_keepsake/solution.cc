#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
const long double EPS = 0.0000000000001;
long long n, p, a[100005], b[100005];
long double can[100005];
bool check(long double m) {
  long double need = 0;
  for (long long i = 1; i <= n; ++i)
    need += max((long double)0, (m - can[i]) * (long double)a[i]);
  if (need > m * (long double)p) return false;
  return true;
}
void solve() {
  cin >> n >> p;
  long long sum = 0;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    can[i] = (long double)b[i] / (long double)a[i];
    sum += a[i];
  }
  if (p >= sum) {
    cout << -1 << '\n';
    return;
  }
  long double l = -EPS, r = 1e14 + EPS;
  for (int i = 1; i <= 500; ++i) {
    long double m = (l + r) / 2;
    if (check(m))
      l = m;
    else
      r = m;
  }
  cout << fixed << setprecision(9) << l << '\n';
}
