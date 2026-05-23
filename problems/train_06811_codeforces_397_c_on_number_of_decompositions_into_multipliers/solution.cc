#include <bits/stdc++.h>
using namespace std;
const long double PI = 2 * acos(0);
const long double eps = 1e-15;
const int inf = 1e9 + 7;
const long long Linf = (long long)1e18 + 7;
const int MOD = 1e9 + 7;
const int LMAX = 1e6 + 7;
const int MAX = 1e5 + 7;
const int BASE = 1e9 + 7;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
long long POW(long long a, long long b) {
  if (b == 0) return 1;
  long long p = POW(a, b / 2);
  p *= p;
  p %= BASE;
  if (b & 1)
    return p * a % BASE;
  else
    return p % BASE;
}
long long inverse_mod(long long a) { return POW(a, BASE - 2); }
long long nCk(long long n, long long k) {
  long long N = 1, K = 1, NK = 1;
  for (int i = (1); i <= (n); i++) {
    N = N * i % BASE;
    if (i <= k) K = K * i % BASE;
    if (i <= n - k) NK = NK * i % BASE;
  }
  K = K * NK % BASE;
  return N * inverse_mod(K) % BASE;
}
map<long long, long long> a;
set<long long> s;
long long n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = (1); i <= (n); i++) {
    long long tmp;
    cin >> tmp;
    for (int j = (2); j <= (sqrt(tmp)); j++) {
      if (tmp % j == 0) {
        s.insert(j);
        while (tmp % j == 0) {
          a[j]++;
          tmp /= j;
        }
      }
    }
    if (tmp != 1) {
      s.insert(tmp);
      a[tmp]++;
    }
  }
  long long res = 1;
  for (typeof(s.begin()) i = s.begin(); i != s.end(); i++) {
    long long tmp = (*i);
    tmp = a[tmp];
    res *= nCk(tmp + n - 1, tmp);
    res %= BASE;
  }
  cout << res;
  return 0;
}
