#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    int j = 0;
    while (i + (1 << (j + 1)) < n) ++j;
    a[i + (1 << j)] += a[i];
    ans += a[i];
    cout << ans << '\n';
  }
  return 0;
}
