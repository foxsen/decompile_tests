#include <bits/stdc++.h>
using namespace std;
const int MAXN = 112345;
int vis[MAXN];
int flag;
int cost[MAXN];
int cnt[MAXN];
int n;
void bfs(int a) {
  flag++;
  queue<pair<int, int>> q;
  vis[a] = flag;
  cnt[a]++;
  q.push({a, 0});
  while (not q.empty()) {
    int u = q.front().first;
    int d = q.front().second;
    q.pop();
    int v[2] = {u / 2, 2 * u};
    for (int i = 0; i < 2; i++) {
      if (v[i] < 0 or v[i] >= MAXN) continue;
      if (vis[v[i]] == flag) continue;
      vis[v[i]] = flag;
      cnt[v[i]]++;
      cost[v[i]] += d + 1;
      q.push({v[i], d + 1});
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    bfs(ai);
  }
  int sol = cost[0];
  for (int i = 1; i < MAXN; i++) {
    if (cnt[i] < n) continue;
    sol = min(sol, cost[i]);
  }
  cout << sol << endl;
}
