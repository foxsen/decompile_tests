#include <bits/stdc++.h>
using namespace std;
const int MAX = 6e3 + 10;
int dp[MAX][MAX];
int DP(int i, int j, const vector<vector<int>> &rightOf) {
  if (i > j) return 0;
  int &answer = dp[i][j];
  if (answer != -1) return answer;
  int add = 0;
  for (int r : rightOf[i])
    if (r == j) add++;
  answer = add + DP(i + 1, j, rightOf);
  for (int r : rightOf[i]) {
    if (r >= j) break;
    int toR = DP(i, r, rightOf);
    int fromR = DP(r + 1, j, rightOf);
    answer = max(answer, add + toR + fromR);
  }
  return answer;
};
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  vector<int> vals;
  for (auto &p : arr) {
    cin >> p.first >> p.second;
    vals.push_back(p.first);
    vals.push_back(p.second);
  }
  sort(arr.begin(), arr.end());
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
  int LIM = (int)vals.size();
  vector<vector<int>> rightOf(LIM);
  for (auto p : arr) {
    p.first = lower_bound(vals.begin(), vals.end(), p.first) - vals.begin();
    p.second = lower_bound(vals.begin(), vals.end(), p.second) - vals.begin();
    rightOf[p.first].push_back(p.second);
  }
  for (int i = 0; i < LIM; ++i)
    for (int j = 0; j < LIM; ++j) dp[i][j] = -1;
  cout << DP(0, LIM - 1, rightOf) << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}
