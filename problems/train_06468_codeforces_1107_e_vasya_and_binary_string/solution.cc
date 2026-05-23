#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<int> val;
vector<vector<vector<long long>>> memo;
long long solve(long long l, long long r, long long p) {
  if (l >= r) return 0;
  if (r - l == 1) return val[p];
  if (memo[l][r][p] != -1) return memo[l][r][p];
  long long ans = val[p] + solve(l + 1, r, 1);
  for (int i = l + 1; i < r; i++) {
    if (s[i] == s[l]) {
      ans = max(ans, solve(l + 1, i, 1) + solve(i, r, p + 1));
    }
  }
  return memo[l][r][p] = ans;
}
int main() {
  cin >> n;
  cin >> s;
  val.resize(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  memo.resize(n + 1,
              vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1)));
  cout << solve(0, n, 1) << endl;
}
