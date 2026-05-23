#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
const long long int N = 1000005;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, x, l, r, ans = 0, left = 1000000000000, right = -1;
    cin >> n >> x >> m;
    long long int xL = x, xR = x;
    for (long long int i = 0; i < m; ++i) {
      cin >> l >> r;
      if (!((l > xR) or (r < xL))) {
        left = min(left, l);
        right = max(right, r);
        xL = left, xR = right;
      }
    }
    cout << (xR - xL + 1) << endl;
  }
  return 0;
}
