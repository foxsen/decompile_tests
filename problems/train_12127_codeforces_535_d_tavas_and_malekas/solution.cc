#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double pi = acos(-1);
const long long int INF = 1e18;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int nax = 1000000 + 10;
int n, arr[nax], fail[nax];
int main() {
  ios::sync_with_stdio(0);
  int n, cnt;
  cin >> n >> cnt;
  string s;
  cin >> s;
  int len = s.length();
  s = "#" + s;
  int j = 0;
  fail[1] = 0;
  for (int i = 2; i <= len; i++) {
    while (j && s[j + 1] != s[i]) j = fail[j];
    if (s[j + 1] == s[i]) j++;
    fail[i] = j;
  }
  vector<pair<int, int> > v;
  while (cnt--) {
    int l;
    cin >> l;
    int r = l + len - 1;
    v.push_back({l, r});
  }
  v.push_back({0, 0});
  v.push_back({n + 1, n + 1});
  sort(v.begin(), v.end());
  int sz = v.size();
  long long int ans = 0, flag = 0;
  int lastprefix = fail[len];
  for (int i = 1; i < sz; i++) {
    int l2 = v[i].first;
    int r1 = v[i - 1].second;
    if (l2 > r1) {
      ans += (l2 - r1 - 1);
    } else {
      int lastlen = (r1 - l2 + 1);
      bool f = 0;
      int lastle = len;
      while (lastle) {
        if (lastle == lastlen) {
          f = 1;
          break;
        }
        lastle = fail[lastle];
      }
      if (f == 0) flag = 1;
    }
  }
  if (flag == 1)
    cout << 0;
  else {
    long long int ans1 = 1;
    for (int i = 1; i <= ans; i++) {
      ans1 = (ans1 % MOD * 26LL) % MOD;
    }
    cout << ans1;
  }
  return 0;
}
