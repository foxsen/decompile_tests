#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(239);
const long long MOD = 1e9 + 7;
const int N = 1e6 + 239;
long long dp[N];
long long sum[N];
int solve() {
  string s;
  if (!(cin >> s)) return 1;
  vector<long long> a;
  int cur = 0;
  for (int i = 0; i < ((int)((s).size())); i++) {
    if (s[i] == '1') {
      a.push_back(cur + 1);
      cur = 0;
    } else
      cur++;
  }
  a.push_back(cur + 1);
  int n = ((int)((a).size()));
  if (n == 1) {
    cout << a[0] - 1 << '\n';
    return 0;
  }
  if (n == 2) {
    cout << a[0] * a[1] % MOD << '\n';
    return 0;
  }
  long long KEK = a[0] * a.back() % MOD;
  a.pop_back();
  reverse(a.begin(), a.end());
  a.pop_back();
  reverse(a.begin(), a.end());
  n = ((int)((a).size()));
  for (int i = 0; i < N; i++) {
    dp[i] = sum[i] = 0;
  }
  vector<int> st;
  st.push_back(-1);
  long long mx = 0;
  for (int i = 0; i < n; i++) {
    if (i) dp[i] = dp[i - 1] * a[i] % MOD;
    if (mx < a[i]) {
      dp[i] = (dp[i] + (a[i] - mx)) % MOD;
      mx = a[i];
    }
    while (((int)((st).size())) > 1 && a[st.back()] <= a[i]) {
      dp[i] += (a[i] - a[st.back()]) *
               (sum[st.back()] - sum[max(st[((int)((st).size())) - 2], 0)]);
      dp[i] %= MOD;
      st.pop_back();
    }
    st.push_back(i);
    sum[i + 1] = (sum[i] + dp[i]) % MOD;
  }
  sum[n]++;
  sum[n] = sum[n] * KEK % MOD;
  cout << (sum[n] % MOD + MOD) % MOD << '\n';
  return 0;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TET = 1e9;
  for (int i = 1; i <= TET; i++) {
    if (solve()) break;
    cout << '\n';
  }
}
