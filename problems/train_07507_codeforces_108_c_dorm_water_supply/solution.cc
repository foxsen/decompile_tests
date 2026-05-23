#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n, p;
  cin >> n >> p;
  std::vector<int> out(n + 1, -1);
  std::vector<int> diameter(n + 1, -1);
  std::vector<bool> in(n + 1, 0);
  int a, b, d;
  for (int i = 0; i < p; i++) {
    cin >> a >> b >> d;
    in[b] = 1;
    out[a] = b;
    diameter[a] = d;
  }
  std::vector<pair<int, pair<int, int>>> tankTapPair;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0 && out[i] != -1) {
      queue<int> q;
      q.push(out[i]);
      int minDi = diameter[i];
      int node;
      while (!q.empty()) {
        node = q.front();
        q.pop();
        if (out[node] != -1) {
          minDi = min(minDi, diameter[node]);
          q.push(out[node]);
        }
      }
      tankTapPair.push_back({i, {node, minDi}});
    }
  }
  cout << tankTapPair.size() << endl;
  for (int i = 0; i < tankTapPair.size(); i++) {
    cout << tankTapPair[i].first << " " << tankTapPair[i].second.first << " "
         << tankTapPair[i].second.second << endl;
  }
}
