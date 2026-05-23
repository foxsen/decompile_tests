#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long mpow(long long a, long long b, long long p = MOD) {
  a = a % p;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b = b >> 1;
  }
  return res % p;
}
const long long N = 2e5 + 100;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  map<long long, long long> ma;
  ma[a[0] + 1]++;
  for (long long i = 1; i < n; i++) {
    long long poss1 = ma[a[i] - 1];
    long long poss2 = ma[a[i] + 1];
    long long poss3 = ma[a[i]];
    if (poss1 == 1 || poss2 == 1 || poss3 == 1) {
    } else {
      ma[a[i] + 1]++;
    }
  }
  long long mn = 0;
  for (auto x : ma) mn += x.second;
  ma.clear();
  ma[a[0] - 1]++;
  for (long long i = 1; i < n; i++) {
    long long poss1 = ma[a[i] - 1];
    long long poss2 = ma[a[i] + 1];
    long long poss3 = ma[a[i]];
    if (poss1 == 0 || poss2 == 0 || poss3 == 0) {
      if (poss1 == 0) {
        ma[a[i] - 1]++;
      } else if (poss3 == 0) {
        ma[a[i]]++;
      } else {
        ma[a[i] + 1]++;
      }
    } else {
    }
  }
  long long mx = 0;
  for (auto x : ma) mx += x.second;
  cout << mn << " " << mx << "\n";
}
