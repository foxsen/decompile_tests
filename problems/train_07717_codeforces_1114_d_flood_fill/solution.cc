#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int NMAX = 5005;
const int INF = 2e5;
int n;
vector<int> arr;
vector<vector<int>> dp(NMAX, vector<int>(NMAX, INF));
int rec(int i, int j) {
  if (dp[i][j] != INF) return dp[i][j];
  if (i == j) return dp[i][j] = 0;
  if (arr[i] == arr[j]) return dp[i][j] = 1 + rec(i + 1, j - 1);
  return dp[i][j] = 1 + min(rec(i + 1, j), rec(i, j - 1));
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (!i)
      arr.push_back(tmp);
    else if (tmp != arr[(int)(arr.size()) - 1])
      arr.push_back(tmp);
  }
  n = (int)(arr.size());
  cout << rec(0, n - 1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
