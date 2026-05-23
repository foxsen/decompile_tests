#include <bits/stdc++.h>
using namespace std;
void print(vector<set<int>> adj) {
  int i = 0;
  cerr << '#' << '\n';
  for (auto o : adj) {
    cerr << (i++) << ": ";
    for (auto e : o) {
      cerr << e << ' ';
    }
    cerr << '\n';
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  int ans = 0;
  while (1) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (adj[i].size() == 1) {
        v.push_back(i);
      }
    }
    for (int i = 0; i < v.size(); i++) {
      set<int>::iterator it = adj[v[i]].begin();
      adj[v[i]].clear();
      adj[*it].erase(v[i]);
    }
    if (v.size())
      ans++;
    else
      break;
  }
  cout << ans << '\n';
  return 0;
}
