#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
bool visited[200005];
int mini, maxi;
void DFS(int a) {
  visited[a] = true;
  mini = min(mini, a);
  maxi = max(maxi, a);
  vector<int>::iterator it;
  for (it = adj[a].begin(); it != adj[a].end(); it++) {
    if (!visited[*it]) {
      DFS(*it);
    }
  }
}
void solve() {
  int n, m, x, y;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
  }
  int count = 0, currMax = 0, currMin = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      mini = INT_MAX;
      maxi = INT_MIN;
      DFS(i);
      if (mini > currMax) {
        currMin = mini;
        currMax = maxi;
        continue;
      } else if (mini > currMin && mini < currMax) {
        count++;
        currMax = max(currMax, maxi);
      }
    }
  }
  cout << count << endl;
}
int main() {
  solve();
  return 0;
}
