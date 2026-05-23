#include <bits/stdc++.h>
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long qmul(long long a, long long b, long long m) {
  long long res = 0;
  while (b) {
    if (b & 1) res = (res + a) % m;
    a = (a << 1) % m;
    b = b >> 1;
  }
  return res;
}
inline long long qpow(long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
inline long long inv(long long x, long long q) { return qpow(x, q - 2, q); }
using namespace std;
const int N = 3e5 + 10;
const double eps = 1e5;
int arr[N];
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[2 * i - 1];
    cin >> arr[2 * i];
  }
  int k;
  cin >> k;
  k--;
  int pos = upper_bound(arr + 1, arr + 2 * n + 1, k) - arr;
  cout << n - (pos - 1) / 2;
}
