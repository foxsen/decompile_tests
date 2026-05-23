#include <bits/stdc++.h>
using namespace std;
long long k, p, ans;
int main() {
  cin >> k >> p;
  for (long long i = 1; i <= k; i++) {
    long long a = i, b = i;
    while (b) {
      a = a * 10 + b % 10;
      b /= 10;
    }
    ans += a % p;
  }
  cout << ans % p;
  return 0;
}
