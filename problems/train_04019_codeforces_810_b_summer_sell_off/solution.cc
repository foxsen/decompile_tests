#include <bits/stdc++.h>
using namespace std;
vector<long long> sale;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, f, ans = 0;
  cin >> n >> f;
  for (long long i = 0; i < n; i++) {
    long long k, l;
    cin >> k >> l;
    ans += min(k, l);
    sale.push_back(min(2 * k, l) - min(k, l));
  }
  sort(sale.rbegin(), sale.rend());
  for (long long i = 0; i < f; i++) ans += sale[i];
  cout << ans << "\n";
  return 0;
}
