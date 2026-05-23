#include <bits/stdc++.h>
using namespace std;
pair<long long int, pair<long long int, long long int> > arr[1005];
vector<long long int> v[1005];
long long int parent[1005], dp[1005][2][2];
long long int sq(long long int x) { return (x * x); }
long long int distance(pair<long long int, long long int> p1,
                       pair<long long int, long long int> p2) {
  return sq(p1.first - p2.first) + sq(p1.second - p2.second);
}
long long int inside(long long int small, long long int big) {
  return distance(arr[small].second, arr[big].second) <=
         sq(arr[small].first - arr[big].first);
}
long long int dfs(long long int cur, long long int parity0,
                  long long int parity1) {
  if (dp[cur][parity0][parity1] != -1) return dp[cur][parity0][parity1];
  long long int ans0 = 0;
  long long int ans1 = 0;
  if (parity0 & 1)
    ans0 = ans0 - sq(arr[cur].first);
  else
    ans0 = ans0 + sq(arr[cur].first);
  for (long long int i = 0; i < v[cur].size(); i++)
    ans0 += dfs(v[cur][i], 1 - parity0, parity1);
  if (parity1 & 1)
    ans1 = ans1 - sq(arr[cur].first);
  else
    ans1 = ans1 + sq(arr[cur].first);
  for (long long int i = 0; i < v[cur].size(); i++)
    ans1 += dfs(v[cur][i], parity0, 1 - parity1);
  return dp[cur][parity0][parity1] = max(ans0, ans1);
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  cout << fixed << setprecision(10);
  long long int i, j, n, x, y, ans = 0, k;
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
  sort(arr + 1, arr + n + 1);
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      if (inside(i, j)) {
        parent[i] = j;
        v[j].push_back(i);
        break;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 0; j < 2; j++) {
      for (k = 0; k < 2; k++) dp[i][j][k] = -1;
    }
  }
  for (i = 1; i <= n; i++) {
    if (parent[i]) continue;
    ans += dfs(i, 0, 0);
  }
  cout << ans * acos(-1) << "\n";
  return 0;
}
