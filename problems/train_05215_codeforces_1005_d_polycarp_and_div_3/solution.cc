#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int dp[N][3];
string str;
int solve(int idx, int m) {
  if (idx == str.size()) return m == 0;
  int &ret = dp[idx][m];
  if (~ret) return ret;
  if (m == 0) return ret = solve(idx + 1, (str[idx] - '0') % 3) + 1;
  return ret = max(solve(idx + 1, (str[idx] - '0') % 3),
                   solve(idx + 1, (m * 10 + (str[idx] - '0')) % 3));
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> str;
  cout << solve(1, (str[0] - '0') % 3);
  return 0;
}
