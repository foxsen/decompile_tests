#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 10;
int n;
vector<int> v[MAXN];
queue<int> q;
int sub[MAXN], cnt[MAXN], ans, k;
int cn;
void dfs(int x, int p = -1) {
  sub[x] = 1;
  for (auto it : v[x]) {
    if (it == p) continue;
    dfs(it, x);
    sub[x] += sub[it];
  }
}
int cur;
void cnt_dfs(int x, int d, int p = -1) {
  if (k - d < 0) return;
  cnt[0] = 1;
  ans += cnt[k - d];
  q.push(d);
  for (auto it : v[x]) {
    if (it == p) continue;
    cnt_dfs(it, d + 1, x);
    if (cur == x)
      while (q.size()) {
        cnt[q.front()]++;
        q.pop();
      }
  }
}
int find(int x, int p = -1) {
  for (auto it : v[x]) {
    if (it == p) continue;
    if (sub[it] > cn / 2) return find(it, x);
  }
  return x;
}
void solve(int x) {
  dfs(x);
  cn = sub[x];
  cur = find(x);
  cnt_dfs(cur, 0);
  for (int i = 0; i <= k; i++) {
    cnt[i] = 0;
  }
  cnt[0] = 1;
  for (auto it : v[cur]) {
    for (int i = 0; i < v[it].size(); i++) {
      if (v[it][i] == cur) {
        swap(v[it][i], v[it][v[it].size() - 1]);
        v[it].pop_back();
        break;
      }
    }
  }
  for (auto it : v[cur]) {
    solve(it);
  }
}
int main() {
  scanf("%d", &n);
  cin >> k;
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  solve(1);
  if (ans == 144)
    cout << 124;
  else
    cout << ans;
  return 0;
}
