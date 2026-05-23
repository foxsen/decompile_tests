#include <bits/stdc++.h>
using namespace std;
const int MN = 1011;
int n;
bool c[MN][MN];
vector<pair<int, int> > res;
void go(int u, int v, bool first) {
  if (u + 1 == v) return;
  for (int x = (u + 1), _b = (v - 1); x <= _b; x++)
    if (c[u][x] && c[x][v]) {
      res.push_back((!first) ? make_pair(1, x) : make_pair(u, v));
      go(u, x, first);
      go(x, v, first);
      break;
    }
}
vector<pair<int, int> > solve(const vector<pair<int, int> >& edges,
                              bool first) {
  res.clear();
  memset(c, 0, sizeof c);
  for (auto e : edges) c[e.first][e.second] = c[e.second][e.first] = true;
  int last = 2;
  for (int i = (3), _b = (n); i <= _b; i++)
    if (c[1][i]) {
      go(last, i, first);
      last = i;
    }
  return res;
}
int main() {
  ios ::sync_with_stdio(false);
  while (cin >> n) {
    vector<pair<int, int> > edges[2];
    for (int turn = 0, _a = (2); turn < _a; turn++) {
      for (int i = (1), _b = (n); i <= _b; i++) {
        int j = (i == n) ? 1 : (i + 1);
        edges[turn].push_back(make_pair(i, j));
      }
      for (int i = (1), _b = (n - 3); i <= _b; i++) {
        int u, v;
        cin >> u >> v;
        edges[turn].push_back(make_pair(u, v));
      }
    }
    auto ans1 = solve(edges[0], true);
    auto ans2 = solve(edges[1], false);
    cout << ans1.size() + ans2.size() << endl;
    reverse(ans2.begin(), ans2.end());
    for (auto x : ans1) cout << x.first << ' ' << x.second << endl;
    for (auto x : ans2) cout << x.first << ' ' << x.second << endl;
  }
  return 0;
}
