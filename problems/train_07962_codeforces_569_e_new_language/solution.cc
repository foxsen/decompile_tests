#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
using namespace std;
using namespace std;
string s, v;
pair<int, int> p[200100];
pair<char, char> t[200100];
vector<int> g[200100];
vector<int> gr[200100];
int ord[200100];
int cnt, n, m;
bool used[200100];
int color[200100];
void dfs(int v) {
  used[v] = 1;
  for (int _n((g[v].size()) - 1), i(0); i <= _n; ++i)
    if (!used[g[v][i]]) dfs(g[v][i]);
  ord[cnt++] = v;
}
void cmp(int v, int id) {
  color[v] = id;
  for (int _n((gr[v].size()) - 1), i(0); i <= _n; ++i)
    if (color[gr[v][i]] == -1) cmp(gr[v][i], id);
}
bool SAT(string t) {
  for (int _n((n)-1), i(0); i <= _n; ++i)
    if (t[i] != '#') {
      if (v[t[i] - 'a'] == 'C')
        g[i].push_back(i + n), gr[i + n].push_back(i);
      else
        g[i + n].push_back(i), gr[i].push_back(i + n);
    }
  cnt = 0;
  for (int _n((n << 1) - 1), i(0); i <= _n; ++i) used[i] = 0, color[i] = -1;
  for (int _n((n << 1) - 1), i(0); i <= _n; ++i)
    if (!used[i]) dfs(i);
  reverse(ord, ord + cnt);
  int id = 0;
  for (int _n((n << 1) - 1), i(0); i <= _n; ++i)
    if (color[ord[i]] == -1) cmp(ord[i], ++id);
  for (int _n((n)-1), i(0); i <= _n; ++i)
    if (t[i] != '#') {
      if (v[t[i] - 'a'] == 'C')
        g[i].pop_back(), gr[i + n].pop_back();
      else
        g[i + n].pop_back(), gr[i].pop_back();
    }
  for (int _n((n)-1), i(0); i <= _n; ++i)
    if (color[i] == color[i + n]) return 0;
  return 1;
}
int main() {
  int C, V;
  C = V = 0;
  cin >> v;
  for (int _n((v.size()) - 1), i(0); i <= _n; ++i) (v[i] == 'V' ? V : C)++;
  cin >> n >> m;
  for (int _n((m)-1), i(0); i <= _n; ++i) {
    cin >> p[i].first >> t[i].first;
    cin >> p[i].second >> t[i].second;
    p[i].first--, p[i].second--;
    if (t[i].first == 'C') p[i].first += n;
    if (t[i].second == 'C') p[i].second += n;
    g[p[i].first].push_back(p[i].second);
    gr[p[i].second].push_back(p[i].first);
    if (p[i].first < n)
      p[i].first += n;
    else
      p[i].first -= n;
    if (p[i].second < n)
      p[i].second += n;
    else
      p[i].second -= n;
    g[p[i].second].push_back(p[i].first);
    gr[p[i].first].push_back(p[i].second);
  }
  cin >> s;
  if (SAT(s)) {
    cout << s << endl;
    return 0;
  } else if (!C || !V) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = (n - 1), _b = (0); i >= _b; --i) {
    pair<int, int> f = {0, 0};
    for (int _n(v.size() - 1), j(s[i] + 1 - 'a'); j <= _n; ++j) {
      if (v[j] == 'C') {
        if (f.first) continue;
        f.first++;
      } else {
        if (f.second) continue;
        f.second++;
      }
      string solve = s;
      solve[i] = 'a' + j;
      for (int _n(n - 1), k(i + 1); k <= _n; ++k) solve[k] = '#';
      if (SAT(solve)) {
        for (int _n(n - 1), k(i + 1); k <= _n; ++k) {
          pair<int, int> g = {0, 0};
          for (int _n((v.size()) - 1), l(0); l <= _n; ++l) {
            if (v[l] == 'C') {
              if (g.first) continue;
              g.first++;
            } else {
              if (g.second) continue;
              g.second++;
            }
            solve[k] = 'a' + l;
            if (SAT(solve)) break;
          }
        }
        cout << solve << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
