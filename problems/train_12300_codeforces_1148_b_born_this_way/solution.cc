#include <bits/stdc++.h>
using namespace std;
vector<long long int> ar, br;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int sum = 0, cnt, b;
  long long int x = 0, k, ans = 0;
  long long int n, m = 1, mx = 0, a, mn = 0;
  cin >> n >> m >> a >> b >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    ar.push_back(a + x);
  }
  for (int i = 1; i <= m; i++) {
    cin >> x;
    br.push_back(x);
  }
  x = 0;
  if (k >= n || k >= m) {
    cout << -1 << endl;
    return 0;
  }
  for (auto it = ar.begin(); it != ar.end(); it++) {
    if (k >= x) {
      auto it1 = lower_bound(br.begin(), br.end(), *it);
      if (it1 == br.end()) {
        cout << -1 << endl;
        return 0;
      } else {
        long long int x1 = distance(br.begin(), it1);
        x1 += k - x;
        if (x1 >= m) {
          cout << -1 << endl;
          return 0;
        }
        ans = max(ans, br[x1] + b);
      }
    } else
      break;
    x++;
  }
  cout << ans << endl;
}
