#include <bits/stdc++.h>
using namespace std;
vector<int> graph[105];
int visited[105] = {0};
int flag = 0;
int dfs(int s, int y) {
  visited[s] = 1;
  for (int i = 0; i < graph[s].size(); i++) {
    int x = graph[s][i];
    if (x == y) {
      flag = 1;
    }
    if (!visited[x]) {
      dfs(x, y);
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  while (n--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      v.push_back(make_pair(x, y));
      for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
          if ((v[j].first < v[i].first && v[i].first < v[j].second) ||
              (v[j].first < v[i].second && v[i].second < v[j].second)) {
            graph[i].push_back(j);
          }
        }
      }
    } else {
      memset(visited, 0, sizeof(visited));
      flag = 0;
      dfs(x - 1, y - 1);
      if (flag)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
