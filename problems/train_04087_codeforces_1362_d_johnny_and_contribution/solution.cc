#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
vector<int> G[maxn];
pair<int, int> topic[maxn];
int orginal[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v), G[v].push_back(u);
  }
  for (int i = 1; i <= N; i++)
    cin >> topic[i].first, orginal[i] = topic[i].first, topic[i].second = i;
  sort(topic + 1, topic + N + 1);
  vector<int> ans;
  int ulti = 1;
  for (int i = 1; i <= N; i++) {
    pair<int, int> cur = topic[i];
    int id = cur.second;
    int color = cur.first;
    int flag = 1;
    vector<int> all;
    for (auto v : G[id]) {
      if (orginal[v] == color) flag = 0;
      all.push_back(orginal[v]);
    }
    vector<int> check(color + 1, 0);
    for (auto v : all)
      if (v < color) check[v] = 1;
    for (int i = 1; i <= color - 1; i++)
      if (!check[i]) flag = 0;
    if (!flag) {
      ulti = 0;
      break;
    }
    ans.push_back(id);
  }
  if (!ulti) {
    cout << -1 << "\n";
    return 0;
  }
  for (auto v : ans) cout << v << " ";
  cout << "\n";
  return 0;
}
