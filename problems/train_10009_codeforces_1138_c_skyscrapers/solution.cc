#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long n, m, a[1005][1005], maxr[1005], maxc[1005];
unordered_map<long long, long long> r[1005], c[1005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) cin >> a[i][j];
  }
  for (long long i = 1; i <= n; i++) {
    set<long long> s;
    s.clear();
    for (long long j = 1; j <= m; j++) s.insert(a[i][j]);
    long long cnt = 1;
    for (auto u : s) r[i][u] = cnt, cnt++;
    maxr[i] = cnt - 1;
  }
  for (long long i = 1; i <= m; i++) {
    set<long long> s;
    s.clear();
    for (long long j = 1; j <= n; j++) s.insert(a[j][i]);
    long long cnt = 1;
    for (auto u : s) c[i][u] = cnt, cnt++;
    maxc[i] = cnt - 1;
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      long long valr = r[i][a[i][j]], valc = c[j][a[i][j]];
      if (valr == valc) {
        cout << max(maxr[i], maxc[j]) << " ";
      } else {
        long long mxr = maxr[i], mxc = maxc[j];
        if (valr < valc) {
          cout << max(maxr[i] + valc - valr, maxc[j]) << " ";
        } else {
          cout << max(maxr[i], maxc[j] + valr - valc) << " ";
        }
      }
    }
    cout << endl;
  }
  return 0;
}
