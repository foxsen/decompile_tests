#include <bits/stdc++.h>
using namespace std;
const int N = 150000, A = 1e6 + 2;
vector<int> p, pdiv[A];
vector<vector<int>> G;
int n, q, a[N], c[N], cp[A], C;
set<pair<int, int>> sol;
void DFS(int u) {
  c[u] = C;
  for (int v : pdiv[a[u]]) {
    if (cp[v] != -1) continue;
    cp[v] = C;
    for (int w : G[v])
      if (c[w] == -1) DFS(w);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 2; i < A; i++) {
    if (!pdiv[i].empty()) continue;
    for (int j = i; j < A; j += i) pdiv[j].push_back(p.size());
    p.push_back(i);
  }
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  G.resize(p.size());
  for (int i = 0; i < n; i++)
    for (int j : pdiv[a[i]]) G[j].push_back(i);
  for (int i = 0; i < n; i++) c[i] = -1;
  for (int i = 0; i < A; i++) cp[i] = -1;
  for (int i = 0; i < n; i++)
    if (c[i] == -1) {
      DFS(i);
      C++;
    }
  for (int i = 0; i < n; i++) {
    vector<int> v;
    for (int d : pdiv[a[i] + 1])
      if (cp[d] != -1) v.push_back(cp[d]);
    for (int j = 0; j < v.size(); j++) {
      if (v[j] != c[i]) sol.insert({min(c[i], v[j]), max(c[i], v[j])});
      for (int k = j + 1; k < v.size(); k++)
        if (v[j] != v[k]) sol.insert({min(v[j], v[k]), max(v[j], v[k])});
    }
  }
  while (q--) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    if (c[s] == c[t])
      cout << "0\n";
    else
      cout << (sol.find({min(c[s], c[t]), max(c[s], c[t])}) == sol.end() ? 2
                                                                         : 1)
           << "\n";
  }
  return 0;
}
