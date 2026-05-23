#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
vector<long long int> ans;
vector<long long int> adj[100005];
void bfs_like_fn(long long int n) {
  priority_queue<long long int, vector<long long int>, greater<long long int> >
      pq;
  pq.push(n);
  while (!pq.empty()) {
    auto fr = pq.top();
    pq.pop();
    if (vis[fr] == true) continue;
    vis[fr] = true;
    ans.push_back(fr);
    for (long long int i = 0; i < adj[fr].size(); i++) {
      if (vis[adj[fr][i]] == false) {
        pq.push(adj[fr][i]);
      }
    }
  }
}
int main() {
  long long int n, m, x, y;
  cin >> n >> m;
  while (m--) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  bfs_like_fn(1);
  for (auto p : ans) cout << p << " ";
  cout << endl;
  return 0;
}
