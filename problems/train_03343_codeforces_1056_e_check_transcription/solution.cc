#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long base = 73;
const int maxn = 1e6 + 10;
long long p[maxn];
int main() {
  string s, t;
  cin >> s >> t;
  int cnt[2] = {0, 0};
  int pr[2][s.length() + 1];
  pr[0][0] = pr[1][0] = 0;
  vector<int> v[2];
  for (int i = 0; i < s.length(); i++) {
    pr[0][i + 1] = pr[0][i];
    pr[1][i + 1] = pr[1][i];
    cnt[s[i] - '0']++;
    pr[s[i] - '0'][i + 1]++;
    v[s[i] - '0'].push_back(i + 1);
  }
  int len = t.length();
  long long hash[len + 1];
  hash[0] = 0;
  p[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p[i] = (p[i - 1] * base) % mod;
  }
  for (int i = 1; i <= len; i++) {
    hash[i] =
        (((hash[i - 1] + p[i - 1] * (t[i - 1] - 'a' + 1) % mod) % mod) + mod) %
        mod;
  }
  int ans = 0;
  for (int i = 1; i <= len / cnt[s[0] - '0']; i++) {
    int ln[2];
    ln[s[0] - '0'] = i;
    ln[1 - (s[0] - '0')] =
        (len - cnt[s[0] - '0'] * ln[s[0] - '0']) / cnt[1 - (s[0] - '0')];
    if (ln[1] * cnt[1] + ln[0] * cnt[0] != len or ln[0] == 0 or ln[1] == 0)
      continue;
    long long hsh[2];
    hsh[s[0] - '0'] = ((p[len + 1 - i] * hash[i] % mod) + mod) % mod;
    int pos = v[1 - (s[0] - '0')][0] - 1;
    int l = pos * i + 1;
    int r = l + ln[1 - (s[0] - '0')] - 1;
    hsh[1 - (s[0] - '0')] =
        ((p[len + 1 - r] * (hash[r] - hash[l - 1]) % mod) + mod) % mod;
    if (hsh[0] == hsh[1]) continue;
    bool ok = true;
    for (int j = 0; j < 2; j++) {
      for (int x : v[j]) {
        int l = pr[0][x - 1] * ln[0] + pr[1][x - 1] * ln[1] + 1;
        int r = l + ln[j] - 1;
        ok &= hsh[j] ==
              ((p[len + 1 - r] * (hash[r] - hash[l - 1]) % mod) + mod) % mod;
      }
    }
    ans += ok;
  }
  cout << ans << endl;
  return 0;
}
