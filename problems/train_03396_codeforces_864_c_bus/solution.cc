#include <bits/stdc++.h>
using namespace std;
long long powermodm(long long x, long long n, long long M) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
long long power(long long _a, long long _b) {
  long long _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a);
    _b /= 2;
    _a = (_a * _a);
  }
  return _r;
}
long long isPrime[100001];
void sieve();
vector<long long> Divisors(long long n);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long a, b, f, k;
  cin >> a >> b >> f >> k;
  long long ans = 0;
  long long x = b, y = a + (a - f);
  for (long long i = 1; i <= k; i++) {
    if (i % 2 != 0) {
      if (x < f) {
        cout << -1;
        return 0;
      }
      if (i == k) {
        if (x < a) {
          ans++;
          if (b < (a - f)) {
            cout << -1;
            return 0;
          }
        }
      } else {
        if (x < (a + a)) {
          if (x >= (a + a - f))
            x = x - a;
          else {
            ans++;
            x = b - (a - f);
          }
        } else {
          x = x - a;
        }
      }
    } else {
      if (x < (a - f)) {
        cout << -1;
        return 0;
      }
      if (i == k) {
        if (x < a) {
          ans++;
          if (b < f) {
            cout << -1;
            return 0;
          }
        }
      } else {
        if (x < (a + a)) {
          if (x >= (a + f)) {
            x = x - a;
          } else {
            ans++;
            x = b - f;
          }
        } else
          x = x - a;
      }
    }
  }
  cout << ans;
}
