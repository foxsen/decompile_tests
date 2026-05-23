#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) cout << p << " ";
}
long long int fact_mod(long long int x) {
  long long int res = x;
  while (x--) {
    if (x == 0) break;
    res = (res * x) % mod;
  }
  return res;
}
long long int pw_mod(long long int a, long long int b) {
  long long int res = 1;
  while (b != 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}
int pos[8000100] = {0};
void kmp(string s) {
  int n = (int)s.length(), i;
  for (i = 0; i < n + 1; i++) pos[i] = 0;
  for (i = 1; i < n; i++) {
    int j = pos[i - 1];
    while (j > 0 && s[i] != s[j]) j = pos[j - 1];
    if (s[i] == s[j]) j++;
    pos[i] = j;
  }
}
long long int mod_lo = 1e9 + 7;
int dp[205][205][205];
bool vis[205][205][205];
void cf_solve() {}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string t;
  cin >> t;
  assert((int)(t).size() == 2);
  if (t[0] == t[1]) {
    int cnt = 0;
    for (char c : s)
      if (c == t[0]) cnt++;
    cnt = min(cnt + k, n);
    cout << cnt * (cnt - 1) / 2 << endl;
    return 0;
  }
  function<int(int, int, int)> go = [&](int pos, int rem, int cnt) -> int {
    if (pos == n) {
      return 0;
    }
    if (vis[pos][rem][cnt]) return dp[pos][rem][cnt];
    vis[pos][rem][cnt] = 1;
    int &ans = dp[pos][rem][cnt];
    if (s[pos] == t[0]) {
      ans = max(ans, go(pos + 1, rem, cnt + 1));
      if (rem) ans = max(ans, cnt + go(pos + 1, rem - 1, cnt));
    } else if (s[pos] == t[1]) {
      ans = max(ans, cnt + go(pos + 1, rem, cnt));
      if (rem) ans = max(ans, go(pos + 1, rem - 1, cnt + 1));
    } else {
      ans = max(ans, go(pos + 1, rem, cnt));
      if (rem) {
        ans = max(ans, cnt + go(pos + 1, rem - 1, cnt));
        ans = max(ans, go(pos + 1, rem - 1, cnt + 1));
      }
    }
    return ans;
  };
  cout << go(0, k, 0) << endl;
  return 0;
}
