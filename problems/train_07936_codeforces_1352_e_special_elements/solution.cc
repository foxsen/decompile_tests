#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long PI = 3.14159265;
const long long siz = 5e5;
int main() {
  int t, i, n, a[8000], ans, s, j, m[8001], ma;
  cin >> t;
  while (t--) {
    cin >> n;
    ma = INT_MIN;
    memset(m, 0, sizeof(m));
    for (i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
      ma = max(ma, a[i]);
    }
    ans = 0;
    for (i = 0; i < n; i++) {
      s = a[i];
      for (j = i + 1; j < n; j++) {
        s += a[j];
        if (s > ma) break;
        ans += m[s];
        m[s] = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
