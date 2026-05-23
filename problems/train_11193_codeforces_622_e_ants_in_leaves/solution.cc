#include <bits/stdc++.h>
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
vector<int> G[500050];
void dfs(int v, int p, int d, vector<int>& dist) {
  bool leaf = true;
  for (int ch : G[v]) {
    if (ch == p) continue;
    leaf = false;
    dfs(ch, v, d + 1, dist);
  }
  if (leaf) dist.push_back(d);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  int ans = 0;
  for (int v : G[0]) {
    vector<int> dist;
    dfs(v, 0, 0, dist);
    sort(dist.begin(), dist.end());
    int size = dist.size();
    for (int i = 0; i < size - 1; i++) {
      dist[i + 1] = max(dist[i] + 1, dist[i + 1]);
    }
    ans = max(dist[size - 1] + 1, ans);
  }
  cout << ans << endl;
  return 0;
}
