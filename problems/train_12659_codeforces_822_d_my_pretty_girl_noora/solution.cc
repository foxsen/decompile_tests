#include <bits/stdc++.h>
using namespace std;
const int N = 6005000;
long long d[N];
int main() {
  srand(time(NULL));
  long long t;
  int l, r;
  cin >> t >> l >> r;
  for (int i = 1; i <= r; i++) d[i] = 1e18;
  d[1] = 0;
  for (int i = 1; i <= r; i++) {
    for (int j = i + i; j <= r; j += i) {
      d[j] = min(d[j], d[i] + (j * 1LL * ((j / i) - 1)) / 2LL);
    }
  }
  long long nw = 1;
  long long ans = 0;
  for (int i = l; i <= r; i++) {
    ans += (nw * (d[i] % 1000000007)) % 1000000007;
    ans %= 1000000007;
    nw *= t;
    nw %= 1000000007;
  }
  cout << ans;
  return 0;
}
