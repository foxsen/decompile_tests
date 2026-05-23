#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-12;
const double PI = acos(-1.0);
const long long mod = 1000000007;
using namespace std;
int n, x, y;
vector<int> a, b, v;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    a.push_back(x);
    b.push_back(y);
    v.push_back(x + y);
  }
  if (n >= 2) {
    while (1) {
      bool same = true;
      for (int i = 1; i < n; i++) {
        int ov = v[i];
        v[i] = min(v[i], v[i - 1] + 1);
        if (v[i] != ov) same = false;
      }
      for (int i = n - 2; i >= 0; i--) {
        int ov = v[i];
        v[i] = min(v[i], v[i + 1] + 1);
        if (v[i] != ov) same = false;
      }
      if (same) break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (v[i] < a[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) ans += (v[i] - a[i]);
  cout << ans << endl;
  for (int i = 0; i < n; i++) cout << v[i] << ' ';
  cout << endl;
  return 0;
}
