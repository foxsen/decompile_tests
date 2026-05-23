#include <bits/stdc++.h>
using namespace std;
const int N = 4000;
const long long MOD = 1e9 + 7;
const double eps = 1e-9;
int n, m, vis[N], vc, e[N], ind[N], outd[N];
vector<pair<int, int> > v;
string s[N];
map<string, int> mp;
vector<vector<int> > g;
char st[5];
vector<int> res;
void build(int u) {
  vector<int> s;
  s.push_back(u);
  while (s.size()) {
    if (e[u]) {
      s.push_back(u);
      int v = g[u].back();
      e[u]--;
      g[u].pop_back();
      u = v;
    } else {
      res.push_back(u);
      u = s.back();
      s.pop_back();
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", st);
    string t = "";
    t += st[0];
    t += st[1];
    if (mp.find(t) == mp.end()) mp[t] = m++;
    s[mp[t]] = t;
    v.push_back(make_pair(mp[t], -1));
    t = "";
    t += st[1];
    t += st[2];
    if (mp.find(t) == mp.end()) mp[t] = m++;
    s[mp[t]] = t;
    v.back().second = mp[t];
  }
  g.resize(m);
  for (int i = 0; i < n; i++) {
    e[v[i].first]++;
    g[v[i].first].push_back(v[i].second);
    outd[v[i].first]++;
    ind[v[i].second]++;
  }
  int in = 0, out = 0, start = 0, end = 0;
  for (int i = 0; i < m; i++) {
    if (ind[i] == outd[i]) continue;
    if (ind[i] - outd[i] == 1)
      in++, end = i;
    else if (outd[i] - ind[i] == 1)
      out++, start = i;
    else {
      puts("NO");
      return 0;
    }
  }
  if (in > 1 || out > 1) {
    puts("NO");
    return 0;
  }
  build(start);
  reverse(res.begin(), res.end());
  string ans = "";
  ans += s[res[0]];
  for (int i = 1; i < res.size(); i++) ans += s[res[i]][1];
  if (ans.size() != n + 2) {
    puts("NO");
    return 0;
  }
  printf("YES\n%s\n", ans.c_str());
  return 0;
}
