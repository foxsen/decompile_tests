#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
long long mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
vector<vector<pair<long long, long long>>> h(2e6 + 1);
vector<vector<long long>> nm(2e6 + 1);
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  long long k = 0;
  bool f = false;
  while (t--) {
    long long n;
    cin >> n;
    ++k;
    if (k == 1 && n == 4) {
      f = true;
    }
    vector<vector<long long>> a(n, vector<long long>(3));
    vector<pair<long long, long long>> mim(n);
    set<long long> st;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 3; j++) {
        cin >> a[i][j];
      }
      a[i][2] = a[i][0] + a[i][1] - a[i][2];
      mim[i].first = max((long long)0, a[i][2] - a[i][1]);
      mim[i].second = min(a[i][0], a[i][2]);
      st.insert(a[i][2]);
      h[a[i][2]].clear();
      nm[a[i][2]].clear();
    }
    for (long long i = 0; i < n; i++) {
      h[a[i][2]].push_back({mim[i].first, mim[i].second});
      nm[a[i][2]].push_back(i);
    }
    long long ans = 0;
    vector<pair<long long, long long>> viv(n);
    for (auto& m : st) {
      vector<pair<long long, long long>> nv;
      for (long long i = 0; i < h[m].size(); i++) {
        nv.push_back({h[m][i].first, nm[m][i] + 1});
        nv.push_back({h[m][i].second + 1, -nm[m][i] - 1});
      }
      sort(nv.begin(), nv.end());
      vector<long long> now;
      map<long long, long long> used;
      for (long long i = 0; i < nv.size(); i++) {
        if (nv[i].second > 0) {
          now.push_back(nv[i].second - 1);
        } else {
          if (used[-nv[i].second]) continue;
          if (!now.empty()) ++ans;
          while (!now.empty()) {
            used[now.back() + 1]++;
            viv[now.back()].first = nv[i].first - 1;
            viv[now.back()].second = m - nv[i].first + 1;
            now.pop_back();
          }
        }
      }
    }
    cout << ans << "\n";
    for (long long i = 0; i < n; i++) {
      cout << a[i][0] - viv[i].first << " " << a[i][1] - viv[i].second << "\n";
    }
  }
}
