#include <bits/stdc++.h>
using namespace std;
string s, t;
int dp[5005][5005];
int get(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  if (i >= s.size() or j >= t.size()) return 0;
  int ret = get(i, j + 1);
  if (s[i] == t[j]) ret = (ret + 1 + get(i + 1, j + 1)) % 1000000007;
  return dp[i][j] = ret;
  ;
}
int main() {
  for (int i = 0; i < 5005; ++i)
    for (int j = 0; j < 5005; ++j) dp[i][j] = -1;
  cin >> s >> t;
  long long ret = 0;
  for (int i = 0; i < s.size(); ++i) ret = (ret + get(i, 0)) % 1000000007;
  cout << ret << endl;
}
