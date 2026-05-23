#include <bits/stdc++.h>
using namespace std;
long long P = 1e9 + 7;
double PI = 3.141592653589793;
const int sqr = 500;
const int arrn = 2e5 + 5;
const int arrn2 = 6e3 + 5;
void solve() {
  string s;
  cin >> s;
  int n = (s.length() - 1) / 2;
  vector<int> spos;
  for (int i = 1; i < (int)s.length(); i += 2) {
    if (s[i] == '*') spos.push_back(i);
  }
  vector<vector<long long>> vals(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i < n + 1; i++) {
    vals[i][i] = (s[2 * i] - '0');
    for (int j = i + 1; j < n + 1; j++) {
      int k = 2 * j - 1;
      long long val = 1;
      while (k > 2 * i && s[k] == '*') {
        val *= (s[k + 1] - '0');
        k -= 2;
      }
      val *= (s[k + 1] - '0');
      if (k > 0)
        vals[i][j] = vals[i][(k - 1) / 2] + val;
      else
        vals[i][j] = val;
    }
  }
  long long out = vals[0][n];
  for (auto i : spos) {
    for (int j = -1; j < 2 * n + 2; j += 2) {
      int l = min(i, j) + 1, r = max(i, j) - 1;
      if (l > r) continue;
      long long val = vals[l / 2][r / 2];
      int k = l - 2;
      while (k >= 0 && s[k + 1] == '*') {
        val *= (s[k] - '0');
        k -= 2;
      }
      int m = r + 2;
      while (m < 2 * n + 1 && s[m - 1] == '*') {
        val *= (s[m] - '0');
        m += 2;
      }
      if (k >= 0) val += vals[0][k / 2];
      if (m < 2 * n + 1) val += vals[m / 2][n];
      out = max(out, val);
    }
  }
  cout << out;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int T = 1;
  while (T--) solve();
}
