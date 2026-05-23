#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int m;
string s;
struct edge {
  int v;
  bool eq;
};
vector<edge> G[2002];
int comp[2002];
long long pow2[2002];
bool DFS(int v) {
  for (edge& e : G[v]) {
    if (comp[e.v] == -1) {
      if (e.eq)
        comp[e.v] = comp[v];
      else
        comp[e.v] = (comp[v] % 2 ? comp[v] - 1 : comp[v] + 1);
      if (!DFS(e.v)) return false;
    } else if ((comp[e.v] == comp[v] && !e.eq) ||
               (comp[e.v] != comp[v] && e.eq))
      return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s;
  m = s.length();
  pow2[0] = 1;
  for (int j = 1; j <= 2 * m + 1; j++) {
    pow2[j] = pow2[j - 1] + pow2[j - 1];
    if (pow2[j] >= MOD) pow2[j] -= MOD;
  }
  long long sol = 0;
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j <= 2 * m + 1; j++) G[j].clear();
    edge e;
    e.eq = false;
    e.v = 2 * m;
    G[2 * m + 1].push_back(e);
    e.v = 2 * m + 1;
    G[2 * m].push_back(e);
    e.eq = true;
    for (int j = 0; j < i - j; j++) {
      e.v = i - j;
      G[j].push_back(e);
      e.v = j;
      G[i - j].push_back(e);
    }
    for (int j = i + 1; j < m; j++) {
      e.v = 2 * m;
      G[j].push_back(e);
      e.v = j;
      G[2 * m].push_back(e);
    }
    e.v = 2 * m + 1;
    G[i].push_back(e);
    e.v = i;
    G[2 * m + 1].push_back(e);
    for (int j = 0; j < m - 1 - j; j++) {
      e.v = m - 1 - j + m;
      G[j + m].push_back(e);
      e.v = j + m;
      G[m - 1 - j + m].push_back(e);
    }
    for (int j = 0; j < m; j++) {
      if (s[j] == '?') continue;
      e.eq = (s[j] == '0');
      e.v = m + j;
      G[j].push_back(e);
      e.v = j;
      G[m + j].push_back(e);
    }
    for (int j = 0; j <= 2 * m + 1; j++) comp[j] = -1;
    int c = 0;
    bool ok = true;
    for (int j = 0; j <= 2 * m + 1 && ok; j++) {
      if (comp[j] != -1) continue;
      comp[j] = 2 * c;
      c++;
      if (!DFS(j)) ok = false;
    }
    if (ok) {
      sol += pow2[c - 1];
      if (sol >= MOD) sol -= MOD;
    }
  }
  cout << sol << endl;
  return 0;
}
