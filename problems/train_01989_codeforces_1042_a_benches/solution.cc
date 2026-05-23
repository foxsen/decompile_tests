#include <bits/stdc++.h>
using namespace std;
const int INF = 100010;
int n, m;
int a[INF];
int ss;
int maxn = 0;
int ans;
int main() {
  cin >> n >> m;
  ss = m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= maxn) maxn = a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (a[i] != maxn) ans += maxn - a[i];
  }
  if (ans >= m)
    cout << maxn;
  else {
    ans = m - ans;
    ans = (ans + n - 1) / n;
    cout << maxn + ans;
  }
  cout << " " << a[n - 1] + m;
  return 0;
}
