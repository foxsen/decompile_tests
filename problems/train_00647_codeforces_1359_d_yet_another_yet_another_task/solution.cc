#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
double pi = acos(-1.0);
long long powerm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % M;
    y = y >> 1;
    x = (x * x) % M;
  }
  return res % M;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long max3(long long a, long long b, long long c) {
  return max(max(a, b), c);
}
long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int val = 1; val <= 30; val++) {
    int tmp = 0;
    int h = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] <= val) tmp += a[i];
      if (tmp < 0) tmp = 0;
      h = max(h, tmp);
    }
    ans = max(ans, h - val);
  }
  cout << ans;
  return 0;
}
