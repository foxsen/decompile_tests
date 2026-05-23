#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3;
int n, m;
vector<int> g[MAXN + 3];
bool used[MAXN + 3];
int d[MAXN + 3][MAXN + 3];
pair<int, int> from[MAXN + 3][4];
pair<int, int> to[MAXN + 3][4];
bool test(int a, int b, int c, int d) {
  return a != b && a != c && a != d && b != c && b != d && c != d;
}
bool test2(int v1, int v2, int v3, int v4) {
  return d[v1][v2] != -1e9 && d[v2][v3] != -1e9 && d[v3][v4] != -1e9;
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  fill(&d[0][0], &d[0][0] + sizeof(d) / sizeof(int), -1e9);
  for (int s = 1; s <= n; s++) {
    queue<int> q;
    d[s][s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto& u : g[v]) {
        if (d[s][u] == -1e9) {
          d[s][u] = d[s][v] + 1;
          q.push(u);
        }
      }
    }
  }
  fill(&to[0][0], &to[0][0] + sizeof(to) / sizeof(pair<int, int>),
       make_pair(-1e9, 0));
  fill(&from[0][0], &from[0][0] + sizeof(from) / sizeof(pair<int, int>),
       make_pair(-1e9, 0));
  for (int v = 1; v <= n; v++) {
    for (int u = 1; u <= n; u++) {
      to[v][3] = make_pair(d[u][v], u);
      for (int j = 3; !(j == 0 || to[v][j - 1] >= to[v][j]); j--) {
        swap(to[v][j], to[v][j - 1]);
      }
      from[v][3] = make_pair(d[v][u], u);
      for (int j = 3; !(j == 0 || from[v][j - 1] >= from[v][j]); j--) {
        swap(from[v][j], from[v][j - 1]);
      }
    }
  }
  auto best = make_tuple(0, 0, 0, 0, 0);
  for (int v = 1; v <= n; v++) {
    for (int u = 1; u <= n; u++) {
      for (int a = 0; a <= 3; a++) {
        for (int b = 0; b <= 3; b++) {
          int k = to[v][a].second;
          int l = from[u][b].second;
          if (test(v, u, k, l) && test2(k, v, u, l)) {
            int dist = to[v][a].first + d[v][u] + from[u][b].first;
            if (get<0>(best) < dist) {
              best = make_tuple(dist, k, v, u, l);
            }
          }
        }
      }
    }
  }
  int a, b, c, d;
  tie(ignore, a, b, c, d) = best;
  cout << a << " " << b << " " << c << " " << d << endl;
  return 0;
}
