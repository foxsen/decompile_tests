#include <bits/stdc++.h>
using namespace std;
const long long mod = 100000007700000049;
const long long MAXN = 3e5 + 5;
int op[MAXN];
vector<int> son[MAXN];
int val[MAXN];
int dfs(int pos) {
  int ans, i;
  if (val[pos] != -1) return val[pos];
  if (op[pos] == 0) {
    ans = 0;
    for (i = 0; i < son[pos].size(); i++) ans += dfs(son[pos][i]);
    return val[pos] = ans;
  } else {
    ans = dfs(son[pos][0]);
    for (i = 1; i < son[pos].size(); i++) ans = min(ans, dfs(son[pos][i]));
    return val[pos] = ans;
  }
}
int main() {
  std::ios::sync_with_stdio();
  int i, j, k, t1, t2, t3, n, m;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> op[i];
  for (i = 2; i <= n; i++) {
    cin >> t1;
    son[t1].push_back(i);
  }
  t1 = 1;
  memset(val, -1, sizeof(val));
  for (i = 2; i <= n; i++)
    if (!son[i].size()) {
      val[i] = 1;
      t1++;
    }
  cout << t1 - dfs(1);
}
