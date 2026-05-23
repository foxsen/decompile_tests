#include <bits/stdc++.h>
using namespace std;
int INT_MAX_VAL = (int)0x3F3F3F3F;
int INT_MIN_VAL = (int)-0x3F3F3F3F;
long long LONG_MAX_VAL = (long long)0x3F3F3F3F3F3F3F3F;
long long LONG_MIN_VAL = (long long)-0x3F3F3F3F3F3F3F3F;
int colors[500006];
vector<pair<int, char> > graph[500006];
int n, m;
int dfs(int v, char c, vector<int>& red, vector<int>& blue) {
  for (auto& p : graph[v]) {
    int w = p.first;
    int use_color = (c == p.second) ? colors[v] : (3 - colors[v]);
    if (colors[w] == 0) {
      colors[w] = use_color;
      if (use_color == 1) {
        red.push_back(w);
      } else {
        blue.push_back(w);
      }
      dfs(w, c, red, blue);
    } else if (colors[w] != use_color) {
      return false;
    }
  }
  return true;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int v, w;
    char c;
    cin >> v >> w >> c;
    graph[v].emplace_back(w, c);
    graph[w].emplace_back(v, c);
  }
  bool is_result = false;
  vector<int> result;
  for (int z = 0; z < 2; ++z) {
    bool is_good = true;
    vector<int> current;
    for (int i = 1; i <= n; ++i) colors[i] = 0;
    for (int i = 1; i <= n; ++i) {
      if (colors[i] == 0) {
        vector<int> red = {i};
        colors[i] = 1;
        vector<int> blue;
        bool res = dfs(i, (z == 0) ? 'B' : 'R', red, blue);
        if (!res) {
          is_good = false;
          break;
        }
        if (red.size() > blue.size()) swap(red, blue);
        for (auto p : red) current.push_back(p);
      }
    }
    if (is_good) {
      if (!is_result || result.size() > current.size()) {
        result = current;
        is_result = true;
      }
    }
  }
  if (is_result) {
    cout << result.size() << '\n';
    for (auto& a : result) {
      cout << a << " ";
    }
    cout << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}
