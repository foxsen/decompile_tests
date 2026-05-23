#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l[300001], r[300001];
    vector<int> x(n);
    for (int i = 0; i <= n; i += 1) {
      l[i] = n;
      r[i] = 0;
    }
    for (int i = 0; i < n; i += 1) {
      cin >> x[i];
      l[x[i]] = min(l[x[i]], i);
      r[x[i]] = max(r[x[i]], i);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    int ans = n, v = 1;
    for (int i = x.size() - 1; i >= 0; i -= 1) {
      if (i + 1 == x.size() || r[x[i]] >= l[x[i + 1]]) {
        v = 1;
      } else {
        v += 1;
      }
      ans = min(ans, (int)x.size() - v);
    }
    cout << ans << endl;
  }
}
