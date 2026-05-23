#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  long long f[n + 1];
  f[0] = 0;
  long long ans[n + 1];
  long long pref[n + 1];
  pref[0] = 0;
  ans[0] = -1;
  for (long long i = 1; i < n + 1; ++i) {
    long long to = ((long long)sqrt(i) + 10) * 2;
    vector<pair<long long, long long>> b;
    for (long long j = 2; j <= to; ++j) {
      if (i >= j * (j + 1) / 2 && (i - j * (j + 1) / 2) % j == 0) {
        long long s = 1 + (i - j * (j + 1) / 2) / j;
        long long t = s + j - 1;
        b.push_back({pref[t] ^ pref[s - 1], j});
      }
    }
    long long mex = 0;
    sort(b.begin(), b.end());
    for (long long k = 0; k < b.size(); ++k) {
      if (mex == b[k].first) mex++;
    }
    f[i] = mex;
    if (f[i] == 0) {
      ans[i] = -1;
    } else {
      long long mn = 1e9;
      for (long long j = 0; j < b.size(); ++j) {
        if (b[j].first == 0) {
          mn = min(mn, b[j].second);
        }
      }
      ans[i] = mn;
    }
    pref[i] = pref[i - 1] ^ f[i];
  }
  cout << ans[n];
}
