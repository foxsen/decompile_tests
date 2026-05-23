#include <bits/stdc++.h>
using namespace std;
long long int n, a[300005], q;
long long int b[300005];
long long int ans[300005];
vector<pair<long long int, long long int> > qur[560];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
  for (int i = 1; i <= q; i++) {
    long long int x, y;
    cin >> x >> y;
    if (y > 550) {
      long long int an = 0;
      while (x <= n) {
        an += a[x];
        x += y;
      }
      ans[i] = an;
    } else {
      qur[y].push_back({x, i});
    }
  }
  for (int i = 1; i <= 550; i++) {
    memset(b, 0, sizeof b);
    for (int j = n; j >= 1; j--) {
      if (j + i <= n)
        b[j] = a[j] + b[j + i];
      else
        b[j] = a[j];
    }
    for (auto j : qur[i]) ans[j.second] = b[j.first];
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
  return 0;
}
