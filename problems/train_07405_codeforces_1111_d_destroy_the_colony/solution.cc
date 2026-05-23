#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 15;
const int MaxA = 256;
const int MOD = 1e9 + 7;
int cnt[MaxA];
int n;
int dp[MaxA][MaxA];
int f[MaxN], rf[MaxN];
int bpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = (long long)res * a % MOD;
    b >>= 1;
    a = (long long)a * a % MOD;
  }
  return res;
}
int cnk(int n, int k) {
  int a = f[n];
  int b = (long long)rf[k] * rf[n - k] % MOD;
  return (long long)a * b % MOD;
}
void prepare() {
  f[0] = f[1] = rf[0] = rf[1] = 1;
  for (int i = 2; i < MaxN; ++i) {
    f[i] = f[i - 1] * (long long)i % MOD;
    rf[i] = bpow(f[i], MOD - 2);
  }
}
void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
void del(int& x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
void addItem(vector<int>& dp, int a, int ms) {
  for (int i = ms; i >= a; --i) add(dp[i], dp[i - a]);
}
void delItem(vector<int>& dp, int a, int ms) {
  for (int i = a; i <= ms; ++i) del(dp[i], dp[i - a]);
}
void preSolve() {
  int ans = (long long)f[n / 2] * f[n / 2] % MOD;
  vector<char> qs;
  for (char q = 'a'; q <= 'z'; ++q) qs.push_back(q);
  for (char q = 'A'; q <= 'Z'; ++q) qs.push_back(q);
  for (char q : qs) ans = (long long)ans * rf[cnt[q]] % MOD;
  vector<int> dp(n / 2 + 1, 0);
  dp[0] = 1;
  for (char q : qs)
    if (cnt[q]) addItem(dp, cnt[q], n / 2);
  for (int p1 = 0; p1 < qs.size(); ++p1)
    if (cnt[qs[p1]]) {
      ::dp[qs[p1]][qs[p1]] = (long long)ans * dp[n / 2] % MOD;
      delItem(dp, cnt[qs[p1]], n / 2);
      for (int p2 = p1 + 1; p2 < qs.size(); ++p2)
        if (cnt[qs[p2]]) {
          delItem(dp, cnt[qs[p2]], n / 2);
          ::dp[qs[p1]][qs[p2]] = ::dp[qs[p2]][qs[p1]] =
              dp[n / 2] * 2ll * ans % MOD;
          addItem(dp, cnt[qs[p2]], n / 2);
        }
      addItem(dp, cnt[qs[p1]], n / 2);
    }
}
void solve(char q, char q1) { cout << dp[q][q1] << '\n'; }
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  prepare();
  string s;
  cin >> s;
  for (char q : s) ++cnt[q];
  n = s.size();
  preSolve();
  int t;
  cin >> t;
  for (int t1 = 1; t1 <= t; ++t1) {
    int p1, p2;
    cin >> p1 >> p2;
    solve(s[p1 - 1], s[p2 - 1]);
  }
  return 0;
}
