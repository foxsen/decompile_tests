#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int m, d, w;
    cin >> m >> d >> w;
    long long mod = w / gcd(d - 1, w);
    long long cur = min(m, d) / mod;
    long long ans = min(m, d) * cur - mod * (cur + 1) * cur / 2;
    cout << ans << '\n';
  }
  return 0;
}
