#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, rest = 0, ans = 0;
  vector<int> a;
  cin >> n >> k;
  a.resize(n);
  for (int i = (0); i < (n); i++) {
    cin >> a[i];
    ans += a[i] / 10;
    rest += 10 - (a[i] + 9) / 10;
    a[i] = 10 - a[i] % 10;
  }
  sort((a).begin(), (a).end());
  for (int i = (0); i < (n); i++) {
    if (a[i] == 10 || k < a[i]) break;
    ans += 1;
    k -= a[i];
  }
  ans += min(k / 10, rest);
  cout << ans << endl;
  return 0;
}
