#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool mod(long double a, long double b) { return a / b - floor(a / b); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < n; i++) {
    long long first;
    cin >> first;
    v.emplace_back(first, i + 1);
  }
  if (n == 2) {
    cout << 1;
    return 0;
  }
  sort((v).begin(), (v).end());
  bool f = true;
  long long d = v[2].first - v[1].first;
  for (long long i = 2; i < n - 1; i++) {
    if (v[i + 1].first - v[i].first != d) {
      f = false;
      break;
    }
  }
  if (f) {
    cout << v[0].second;
    return 0;
  }
  f = true;
  d = v[2].first - v[0].first;
  for (long long i = 2; i < n - 1; i++) {
    if (v[i + 1].first - v[i].first != d) {
      f = false;
      break;
    }
  }
  if (f) {
    cout << v[1].second;
    return 0;
  }
  f = true;
  d = v[1].first - v[0].first;
  for (long long i = 1; i < n - 2; i++) {
    if (v[i + 1].first - v[i].first != d) {
      f = false;
      break;
    }
  }
  if (f) {
    cout << v[n - 1].second;
    return 0;
  }
  vector<long long> a(n - 1, 0);
  for (long long i = 0; i < n - 1; i++) a[i] = v[i + 1].first - v[0].first;
  long long i = 1, k = 2, count = 0, temp = 3;
  while (i < n - 1) {
    if (a[i] != k * a[0]) {
      i++;
      if (a[i] != k * a[0]) {
        cout << -1;
        return 0;
      } else {
        if (count >= 1) {
          cout << -1;
          return 0;
        }
        temp = v[i].second;
        count++;
      }
    }
    i++;
    k++;
  }
  cout << temp;
}
