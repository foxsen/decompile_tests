#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  long long int l, k, s = 0, ans = 0, p = 1, m = 1e+9 + 7;
  cin >> a;
  l = a.length();
  for (long long int i = l - 1; i >= 0; i--) {
    k = (((i * (i + 1)) / 2) % m * p % m + s % m) % m;
    s = (s + p * (l - i) % m) % m;
    p = (p * 10) % m;
    ans = (ans + (a[i] - '0') * k % m) % m;
  }
  cout << ans;
  return 0;
}
