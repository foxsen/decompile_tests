#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
const int mod = 1e9 + 7;
long long rec(int a, int b, int c, int s) {
  if (a < b + c) return (long long)0;
  long long cur = min(s, a - b - c);
  return (cur + 1) * (cur + 2) / 2;
}
int main() {
  long long a[6], l;
  cin >> a[0] >> a[1] >> a[2] >> l;
  for (long long i = 0; i <= l; i++) {
    ans += (l - i + 1) * (l - i + 2) / 2;
  }
  for (long long j = 0; j <= l; j++) {
    ans -= rec(a[0] + j, a[1], a[2], l - j);
    ans -= rec(a[1] + j, a[0], a[2], l - j);
    ans -= rec(a[2] + j, a[0], a[1], l - j);
  }
  cout << ans;
  return 0;
}
