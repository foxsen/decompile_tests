#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 0; cin >> n;
  for(long long i = 1; i <= n; ++i) for(long long j = 1; i*j <= n; ++j) ans += i*j;
  cout << ans << "\n";
  return 0;
}