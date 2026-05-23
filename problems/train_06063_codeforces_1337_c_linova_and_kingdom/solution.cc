#include <bits/stdc++.h>
using namespace std;
vector<long long int> v1[200005], v2;
long long int level[200005], start[200005], finish[200005], cnt;
void dfs(long long int x, long long int parent, long long int lev) {
  start[x] = ++cnt;
  level[x] = lev;
  long long int i, sz = v1[x].size();
  for (i = 0; i < sz; i++) {
    long long int y = v1[x][i];
    if (y == parent) continue;
    dfs(y, x, lev + 1);
  }
  finish[x] = ++cnt;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, k, i, a, b, sum = 0;
  cin >> n >> k;
  for (i = 1; i <= n - 1; i++) {
    cin >> a >> b;
    v1[a].push_back(b);
    v1[b].push_back(a);
  }
  dfs(1, 0, 0);
  for (i = 1; i <= n; i++)
    v2.push_back(level[i] - (finish[i] - start[i]) / 2ll);
  sort(v2.rbegin(), v2.rend());
  for (i = 0; i < k; i++) sum += v2[i];
  cout << sum << endl;
  return 0;
}
