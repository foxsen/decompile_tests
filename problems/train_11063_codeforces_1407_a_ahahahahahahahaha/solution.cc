#include <bits/stdc++.h>
using namespace std;
const long long N = 205;
const long long mod = 1000000007;
long long bp(long long x, long long y) {
  long long ans = 1;
  x;
  while (y) {
    if (y & 1) ans = ans * x;
    x = x * x;
    y >>= 1;
  }
  return ans;
}
long long mod_inverse(long long x) { return bp(x, mod - 2); }
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long max(long long a, long long b) {
  if (a < b) swap(a, b);
  return a;
}
long long min(long long a, long long b) {
  if (a > b) swap(a, b);
  return a;
}
long long countSetBits(long long n) {
  long long count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> one, zero;
    long long a[n];
    for (long long i = 0; i < n; i++)
      cin >> a[i], (a[i] == 1 ? one.push_back(i) : zero.push_back(i));
    if (one.size() <= n / 2) {
      cout << zero.size() << '\n';
      for (long long i = 0; i < zero.size(); i++) cout << 0 << " ";
      cout << '\n';
    } else {
      if (one.size() % 2 == 0) {
        cout << one.size() << '\n';
        for (long long i = 0; i < one.size(); i++) cout << 1 << " ";
        cout << '\n';
      } else {
        one.pop_back();
        cout << one.size() << '\n';
        for (long long i = 0; i < one.size(); i++) cout << 1 << " ";
        cout << '\n';
      }
    }
  }
}
signed main() { solve(); }
