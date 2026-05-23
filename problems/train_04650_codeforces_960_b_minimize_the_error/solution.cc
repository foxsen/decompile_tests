#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  ;
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  k1 += k2;
  int a[n], b[n];
  long long c[n];
  for (long long i = 0; i < (long long)(n); i++) cin >> a[i];
  for (long long i = 0; i < (long long)(n); i++) cin >> b[i];
  for (long long i = 0; i < (long long)(n); i++) c[i] = abs(a[i] - b[i]);
  sort(c, c + n);
  reverse(c, c + n);
  while (k1--) {
    c[0] ? c[0]-- : c[0]++;
    sort(c, c + n);
    reverse(c, c + n);
  }
  long long ans = 0;
  for (long long i = 0; i < (long long)(n); i++) ans += c[i] * c[i];
  cout << ans;
  return 0;
}
