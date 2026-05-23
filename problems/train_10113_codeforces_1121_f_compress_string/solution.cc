#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5123;
string t;
int n, a, b;
int memo[MAXN];
int step[MAXN];
int z[MAXN + MAXN];
void zfunction(const string& s) {
  memset(z, 0, sizeof z);
  int n = s.size();
  int L = 0, R = 0;
  for (int i = 1; i < n; i++) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R - L] == s[R]) R++;
      z[i] = R - L;
      R--;
    } else {
      int k = i - L;
      if (z[k] < R - i + 1)
        z[i] = z[k];
      else {
        L = i;
        while (R < n && s[R - L] == s[R]) R++;
        z[i] = R - L;
        R--;
      }
    }
  }
}
int getBiggest(int x) {
  string s;
  for (int i = x; i < n; ++i) s += t[i];
  s += '#';
  int start = s.size();
  for (int i = 0; i < x; ++i) s += t[i];
  int ans = 0;
  zfunction(s);
  for (int i = start; i < s.size(); ++i) {
    ans = max(ans, z[i]);
  }
  return x + ans;
}
int main() {
  cin >> n >> a >> b;
  cin >> t;
  for (int i = 0; i < n; ++i) {
    step[i] = getBiggest(i);
  }
  memo[n] = 0;
  for (int i = n - 1; i >= 0; --i) {
    memo[i] = memo[i + 1] + a;
    memo[i] = min(memo[i], memo[step[i]] + b);
  }
  cout << memo[0] << endl;
  return 0;
}
