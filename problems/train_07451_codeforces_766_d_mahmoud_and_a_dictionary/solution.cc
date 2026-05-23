#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int rar[101000], e[101000], r[101000], xr[101000];
bool vis[101000];
vector<pair<int, int> > v[101000];
vector<pair<pair<int, int>, pair<int, int> > > ss;
int root(int x) {
  while (rar[x] != x) {
    rar[x] = rar[rar[x]];
    x = rar[x];
  }
  return x;
}
void un(int a, int b, int x) {
  int rta = root(a);
  int rtb = root(b);
  if (r[rta] > r[rtb])
    rar[rtb] = rta;
  else if (r[rtb] > r[rta])
    rar[rta] = rtb;
  else {
    rar[rta] = rtb;
    r[rtb]++;
  }
  v[a].push_back(make_pair(x, b));
  v[b].push_back(make_pair(x, a));
}
void dfs(int s, int xx) {
  vis[s] = true;
  xr[s] = xx;
  for (int i = 0; i < v[s].size(); i++)
    if (!vis[v[s][i].second]) dfs(v[s][i].second, (xx ^ v[s][i].first));
}
int main() {
  int n, m, q, t, x, y, ind;
  string s, s1, s2;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    mp[s] = i;
    rar[i] = i;
    r[i] = 0;
  }
  int ans[m + 1], ansq[q + 1];
  for (int i = 1; i <= m; i++) {
    ans[i] = 1;
    cin >> t >> s1 >> s2;
    x = mp[s1];
    y = mp[s2];
    if (root(x) != root(y))
      un(x, y, t - 1);
    else
      ss.push_back(make_pair(make_pair(i, t), make_pair(mp[s1], mp[s2])));
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(root(i), 0);
  for (int i = 0; i < ss.size(); i++) {
    ind = ss[i].first.first;
    t = ss[i].first.second;
    x = ss[i].second.first;
    y = ss[i].second.second;
    if (((xr[x] ^ xr[y]) + 1) != t) ans[ind] = 0;
  }
  for (int i = 1; i <= q; i++) {
    cin >> s1 >> s2;
    x = mp[s1];
    y = mp[s2];
    if (root(x) != root(y))
      ansq[i] = 3;
    else
      ansq[i] = (xr[x] ^ xr[y]) + 1;
  }
  for (int i = 1; i <= m; i++)
    if (ans[i])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  for (int i = 1; i <= q; i++) cout << ansq[i] << endl;
}
