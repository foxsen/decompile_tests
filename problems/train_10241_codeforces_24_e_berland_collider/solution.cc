#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long int input() {
  long long int n;
  cin >> n;
  return n;
}
long long int poww(long long int a, long long int b, long long int md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const long long int MAXN = 5e5 + 10;
const long long int MAXA = 101;
const long long int INF = 1e5;
const long long int MOD = 1e9 + 7;
const long double PI = 4 * atan((long double)1);
long long int n, x[MAXN], v[MAXN];
bool chk(long double k) {
  long double mx = -1e100;
  for (long long int i = 0; i < n; i++) {
    if (v[i] > 0) {
      mx = max(mx, x[i] + v[i] * k);
    } else {
      if (x[i] + v[i] * k <= mx) return 1;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> v[i];
  long double l = -1, r = 1e15;
  while (r - l > 1e-9) {
    long double mid = (l + r) / 2;
    if (chk(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << fixed << setprecision(20);
  cout << (r == 1e15 ? -1.0 : r) << '\n';
  return 0;
}
