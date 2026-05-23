#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int maxn = 2005;
long long n, m;
long long d[maxn];
int vis[maxn];
vector<long long> g[maxn], w[maxn];
char s[maxn][maxn];
void dfs(int x) {
  vis[x] = 1;
  for (int i = 0; i < g[x].size(); i++) {
    int nxt = g[x][i];
    int wgt = w[x][i];
    if (d[nxt] < d[x] + wgt) {
      d[nxt] = d[x] + wgt;
      if (vis[nxt]) {
        cout << "No" << endl;
        exit(0);
      }
      dfs(nxt);
    }
  }
  vis[x] = 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> (s[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '=')
        g[i].push_back(j + n), g[j + n].push_back(i), w[i].push_back(0),
            w[j + n].push_back(0);
      else if (s[i][j] == '>')
        g[j + n].push_back(i), w[j + n].push_back(1);
      else if (s[i][j] == '<')
        g[i].push_back(j + n), w[i].push_back(1);
    }
  }
  for (int i = 1; i <= n + m; i++) dfs(i);
  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++) cout << d[i] + 1 << " ";
  cout << endl;
  for (int i = n + 1; i <= n + m; i++) cout << d[i] + 1 << " ";
  cout << endl;
  return 0;
}
