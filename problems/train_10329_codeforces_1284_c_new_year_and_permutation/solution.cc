#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  long long fact[n + 1];
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % m;
  for (long long i = 1; i <= n; i++) {
    long long cnt = (fact[i] * fact[n - i + 1]) % m;
    cnt = cnt * (n - i + 1);
    ans = (ans + cnt) % m;
  }
  cout << ans << endl;
}
