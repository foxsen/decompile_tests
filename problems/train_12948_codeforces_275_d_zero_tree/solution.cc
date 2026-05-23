#include <bits/stdc++.h>
using namespace std;
long long v[100010];
int n, t1, t2;
vector<int> g[100010];
long long sum;
pair<long long, long long> dfs(int p, int prev) {
  long long a = 0, b = 0;
  for (int i = 0; i < g[p].size(); i++) {
    if (prev == g[p][i]) continue;
    pair<long long, long long> tmp = dfs(g[p][i], p);
    a = max(a, tmp.first);
    b = max(b, tmp.second);
  }
  v[p] += a - b;
  if (v[p] > 0)
    b += v[p];
  else
    a -= v[p];
  return make_pair(a, b);
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> t1 >> t2;
    t1--;
    t2--;
    g[t1].push_back(t2);
    g[t2].push_back(t1);
  }
  for (int i = 0; i < n; i++) cin >> v[i];
  pair<long long, long long> res = dfs(0, -1);
  cout << res.first + res.second << endl;
}
