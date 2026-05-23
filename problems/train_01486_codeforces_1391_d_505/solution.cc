#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7, mod = 1e9 + 7, MAXN = 1e6 + 7;
const double eps = 1e-9;
const long long INF = 1e18, inf = 1e9;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
string a[maxn];
const int L = (1 << 4);
int dp[L];
int dp1[L];
int get(int mask, int col) {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (((mask >> i) & 1) != (a[i][col] - '0')) ++ans;
  }
  return ans;
}
bool match[L][L];
bool M(int mask, int mask1) {
  vector<int> L, R;
  for (int i = 0; i < n; ++i) {
    L.push_back((mask >> i) & 1);
    R.push_back((mask1 >> i) & 1);
  }
  for (int i = 1; i < n; ++i) {
    if ((L[i] + R[i] + L[i - 1] + R[i - 1]) % 2 == 0) return false;
  }
  return true;
}
int get1(int mask, int row) {
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    if (((mask >> i) & 1) != (a[row][i] - '0')) ++ans;
  }
  return ans;
}
bool M1(int mask, int mask1) {
  vector<int> L, R;
  for (int i = 0; i < m; ++i) {
    L.push_back((mask >> i) & 1);
    R.push_back((mask1 >> i) & 1);
  }
  for (int i = 1; i < m; ++i) {
    if ((L[i] + R[i] + L[i - 1] + R[i - 1]) % 2 == 0) return false;
  }
  return true;
}
void print(int mask) {
  for (int i = 0; i < n; ++i) {
    cout << ((mask >> i) & 1);
  }
  cout << '\n';
}
void solve() {
  cin >> n >> m;
  if (n == 1 || m == 1) {
    cout << "0\n";
    return;
  }
  if (n >= 4 && m >= 4) {
    cout << -1;
    return;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n < 4) {
    for (int i = 0; i < (1 << n); ++i) {
      for (int j = 0; j < (1 << n); ++j) {
        match[i][j] = M(i, j);
      }
    }
    for (int i = 0; i < L; ++i) dp[i] = inf;
    for (int i = 0; i < L; ++i) dp1[i] = inf;
    for (int mask = 0; mask < (1 << n); ++mask) {
      dp[mask] = get(mask, 0);
    }
    for (int i = 1; i < m; ++i) {
      for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
        int add = get(mask1, i);
        for (int mask = 0; mask < (1 << n); ++mask) {
          if (match[mask][mask1]) {
            dp1[mask1] = min(dp1[mask1], dp[mask] + add);
          }
        }
      }
      for (int j = 0; j < (1 << n); ++j) {
        dp[j] = dp1[j];
        dp1[j] = inf;
      }
    }
    int ans = inf;
    for (int i = 0; i < (1 << n); ++i) {
      ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
  } else {
    for (int i = 0; i < (1 << n); ++i) {
      for (int j = 0; j < (1 << n); ++j) {
        match[i][j] = M1(i, j);
      }
    }
    for (int i = 0; i < L; ++i) dp[i] = inf;
    for (int i = 0; i < L; ++i) dp1[i] = inf;
    for (int mask = 0; mask < (1 << m); ++mask) {
      dp[mask] = get1(mask, 0);
    }
    for (int i = 1; i < n; ++i) {
      for (int mask1 = 0; mask1 < (1 << m); ++mask1) {
        int add = get1(mask1, i);
        for (int mask = 0; mask < (1 << m); ++mask) {
          if (match[mask][mask1]) {
            dp1[mask1] = min(dp1[mask1], dp[mask] + add);
          }
        }
      }
      for (int j = 0; j < (1 << m); ++j) {
        dp[j] = dp1[j];
        dp1[j] = inf;
      }
    }
    int ans = inf;
    for (int i = 0; i < (1 << m); ++i) {
      ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
