#include <bits/stdc++.h>
using namespace std;
const long long MX = 100000;
const long long MOD = 1000000007;
long long fast_exp(long long base, long long exp, long long mod) {
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, l, x, y;
  cin >> n >> l >> x >> y;
  vector<long long> v(n);
  for (int i = 0, _i = (n); i < _i; ++i) cin >> v[i];
  bool f1, f2;
  f1 = f2 = false;
  for (int i = 0, _i = (n); i < _i; ++i) {
    if (binary_search(v.begin() + i, v.end(), v[i] + x)) f1 = true;
    if (binary_search(v.begin() + i, v.end(), v[i] + y)) f2 = true;
    if (f1 && f2) {
      cout << 0;
      return 0;
    }
  }
  if (f1 || f2) {
    cout << 1 << "\n";
    cout << (f1 ? y : x);
    return 0;
  }
  for (int i = 0, _i = (n); i < _i; ++i) {
    long long p = v[i] + x;
    if (p >= 0 && p <= l &&
        (binary_search(v.begin(), v.end(), p - y) ||
         binary_search(v.begin(), v.end(), p + y))) {
      cout << 1 << "\n" << p;
      return 0;
    }
    p = v[i] - x;
    if (p >= 0 && p <= l &&
        (binary_search(v.begin(), v.end(), p - y) ||
         binary_search(v.begin(), v.end(), p + y))) {
      cout << 1 << "\n" << p;
      return 0;
    }
    p = v[i] + y;
    if (p >= 0 && p <= l &&
        (binary_search(v.begin(), v.end(), p - x) ||
         binary_search(v.begin(), v.end(), p + x))) {
      cout << 1 << "\n" << p;
      return 0;
    }
    p = v[i] - y;
    if (p >= 0 && p <= l &&
        (binary_search(v.begin(), v.end(), p - x) ||
         binary_search(v.begin(), v.end(), p + x))) {
      cout << 1 << "\n" << p;
      return 0;
    }
  }
  cout << 2 << "\n";
  cout << x << " " << y;
  return 0;
}
