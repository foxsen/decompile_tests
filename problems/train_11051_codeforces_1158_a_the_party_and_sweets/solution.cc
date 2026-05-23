#include <bits/stdc++.h>
using namespace std;
long long ans;
int main() {
  long long n, m, s1 = 0, s2 = 0;
  cin >> n >> m;
  vector<long long> b, g;
  for (int i = 0; i < n; i++) {
    long long bi;
    cin >> bi;
    b.push_back(bi);
  }
  long long x = *max_element(b.begin(), b.end());
  for (int i = 0; i < m; i++) {
    long long gj;
    cin >> gj;
    if (x > gj) {
      cout << "-1" << endl;
      return 0;
    }
    g.push_back(gj);
  }
  s1 = accumulate(b.begin(), b.end(), 0LL);
  s2 = accumulate(g.begin(), g.end(), 0LL);
  sort(b.begin(), b.end());
  ans = m * s1 + s2;
  bool ok = false;
  for (int i = 0; i < m; i++) {
    if (g[i] == b[n - 1]) {
      ok = true;
      break;
    }
  }
  if (ok) {
    ans -= m * b[n - 1];
  } else {
    ans -= (m - 1) * b[n - 1] + b[n - 2];
  }
  cout << ans << endl;
}
