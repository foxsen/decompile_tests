#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long PRIME = 999727999;
long long PRIME2 = 999999937;
long long INF = LLONG_MAX / 4;
template <class F1, class F2>
ostream& operator<<(ostream& os, const pair<F1, F2>& p) {
  return os << p.first << ' ' << p.second;
}
template <class F1, class F2>
istream& operator>>(istream& is, pair<F1, F2>& p) {
  return is >> p.first >> p.second;
}
template <class F>
ostream& operator<<(ostream& os, const std::vector<F>& v) {
  for (int i = 0; i < (int)v.size(); i++) os << v[i] << " ";
  return os;
}
template <class F>
istream& operator>>(istream& is, std::vector<F>& v) {
  for (int i = 0; i < (int)v.size(); i++) is >> v[i];
  return is;
}
vector<string> split(const std::string& s, char delim) {
  vector<string> e;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) e.push_back(item);
  return e;
}
long long Pow(long long a, long long b, long long Mo) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % Mo)
    if (b & 1) ans = ans * a % Mo;
  return ans;
}
long long _div(long long a, long long b) {
  return (a * Pow(b, MOD - 2, MOD)) % MOD;
}
long long nCr(long long n, long long r) {
  static long long MAXF = 1e6;
  static std::vector<long long> fact(MAXF, 1);
  for (int i = 1; i < MAXF; ++i) fact[i] = (fact[i - 1] * i) % MOD;
  MAXF = 0;
  return (fact[n] * Pow((fact[r] * fact[n - r]) % MOD, MOD - 2, MOD)) % MOD;
}
vector<int> Zfunc(string& s) {
  int n = s.length();
  vector<int> z(n, 0);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
    if (r < i + z[i] - 1) l = i, r = i + z[i] - 1;
  }
  return z;
}
string s;
int l;
std::vector<std::vector<long long> > DP;
long long getWaysAny(int c, int left) {
  if (c > left) return 0;
  return nCr(left, c);
}
long long getWays(int c, int takencare) {
  if (takencare == l) {
    if (c == 0) return 1;
    return 0;
  }
  long long& w = DP[c][takencare];
  if (w != -1) return w;
  w = 0;
  if (s[takencare] == '1') {
    if (c > 0) w = (w + getWays(c - 1, takencare + 1)) % MOD;
    w = (w + getWaysAny(c, l - (takencare + 1))) % MOD;
  } else {
    w = (w + getWays(c, takencare + 1)) % MOD;
  }
  return w;
}
long long solve() {
  int k;
  cin >> s >> k;
  l = s.length();
  if (k == 0) {
    return 1;
  }
  DP.resize(1002, std::vector<long long>(1002, -1));
  if (k == 1) {
    return (getWays(1, 0) + MOD - 1) % MOD;
  }
  long long w = 0;
  for (int i = 2; i <= 1000; ++i) {
    long long needk = 0;
    long long i2 = i;
    while (i2 > 1) {
      i2 = __builtin_popcount(i2);
      needk++;
    }
    if (needk == k - 1) {
      w = (w + getWays(i, 0)) % MOD;
    }
  }
  return w;
}
int main(int argc, char const* argv[]) {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout << solve();
  return 0;
}
