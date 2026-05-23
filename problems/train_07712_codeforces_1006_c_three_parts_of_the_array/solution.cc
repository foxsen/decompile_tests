#include <bits/stdc++.h>
using namespace std;
const int sz = 2e5 + 9;
int n;
long long a[sz];
long long cs[sz], csr[sz];
multiset<long long> second;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cs[i] = cs[i - 1] + a[i];
  }
  for (int i = n; i >= 1; i--) csr[i] = csr[i + 1] + a[i];
  for (int i = n; i >= 2; i--) second.insert(csr[i]);
  second.insert(0);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (second.count(cs[i])) ans = cs[i];
    second.erase(second.find(csr[i + 1]));
  }
  cout << ans;
  return 0;
}
