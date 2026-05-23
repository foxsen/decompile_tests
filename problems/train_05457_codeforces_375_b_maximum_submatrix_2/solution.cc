#include <bits/stdc++.h>
using namespace std;
long long int expo(long long int x, long long int n, long long int M) {
  long long int res = 1;
  while (n) {
    if (n % 2) {
      res = (res * x) % M;
    }
    x = (x * x) % M;
    n /= 2;
  }
  return res;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<vector<long long int> > v(m, vector<long long int>(n, 0));
  for (long long int i = 0; i <= n - 1; i++) {
    string x;
    cin >> x;
    long long int sz = x.size(), c = 0;
    for (long long int j = 0; j <= sz - 1; j++) {
      if (x[j] == '1')
        c++;
      else {
        c = 0;
      }
      v[j][i] = c;
    }
  }
  long long int ans = 0;
  for (long long int i = 0; i <= m - 1; i++) {
    sort(v[i].rbegin(), v[i].rend());
    long long int mi = LLONG_MAX;
    for (long long int h = 1; h <= n; h++) {
      mi = min(mi, v[i][h - 1]);
      ans = max(ans, h * mi);
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1, test = 0;
  while (t--) {
    solve();
  }
}
