#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a;
    cin >> a;
    long long ans = 0;
    while (a > 0) {
      ans += a % 2;
      a /= 2;
    }
    ans = pow(2, ans);
    cout << ans << "\n";
  }
  return 0;
}
