#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 2e7 + 10;
int calc(int first) {
  int cnt = 0;
  long long res = 0;
  while (first) {
    res |= (1 << (first % 10));
    first /= 10;
  }
  while (res) {
    res -= res & -res;
    ++cnt;
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(false);
  int __;
  cin >> __;
  while (__--) {
    long long n, k;
    cin >> n >> k;
    while (calc(n) > k) {
      long long f = n, t = 1;
      while (calc(f / 10) > k) {
        f /= 10;
        t *= 10;
      };
      ++f;
      n = f * t;
    }
    cout << n << '\n';
  }
  return 0;
}
