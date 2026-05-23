#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > mv;
vector<pair<int, int> > res;
bool vi(int ac, int fa, int ma, int ta) {
  int ne = mv[ac].size();
  if (ac == 0) ne++;
  if (ne > ma || (ne == ma && ta)) return false;
  int ot = ta - 1;
  res.push_back(pair<int, int>(ac + 1, ta));
  for (int i = 0; i < mv[ac].size(); i++) {
    if (mv[ac][i] != fa) {
      if (ta == ma - 1) {
        ta = ma - ne - 1;
        res.push_back(pair<int, int>(ac + 1, ta));
      }
      if (!vi(mv[ac][i], ac, ma, ta + 1)) return false;
      ta++;
      res.push_back(pair<int, int>(ac + 1, ta));
    }
  }
  if (ac && ta > ot) {
    res.push_back(pair<int, int>(ac + 1, ot));
  }
  return true;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  mv.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    mv[u].push_back(v);
    mv[v].push_back(u);
  }
  int ma = 0;
  for (int i = 1; i < n; i++)
    if (mv[i].size() > ma) ma = mv[i].size();
  if (mv[0].size() == ma) ma++;
  while (!vi(0, -1, ma, 0)) res.clear(), ma++;
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++)
    cout << res[i].first << ' ' << res[i].second << endl;
  return 0;
}
