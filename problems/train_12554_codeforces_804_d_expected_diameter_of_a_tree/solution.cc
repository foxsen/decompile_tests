#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int N, M, Q;
vector<int> G[MAXN];
int CC[MAXN], CCN;
vector<int> CCv[MAXN], d[MAXN], dd[MAXN];
int diam[MAXN];
int bfsd[2][MAXN];
int bfs(int v, int di, int cc = -1) {
  queue<pair<int, int> > q;
  q.push({v, -1});
  bfsd[di][v] = 0;
  while (!q.empty()) {
    v = q.front().first;
    int p = q.front().second;
    q.pop();
    if (cc != -1) {
      CC[v] = cc;
      CCv[cc].push_back(v);
    }
    for (int i = 0; i < (int)G[v].size(); i++) {
      int u = G[v][i];
      if (u == p) continue;
      bfsd[di][u] = bfsd[di][v] + 1;
      q.push({u, v});
    }
  }
  return v;
}
void makeCC(int v) {
  int x = bfs(v, 0, CCN);
  int y = bfs(x, 0);
  bfs(y, 1);
  diam[CCN] = bfsd[0][y];
  for (int i = 0; i < (int)CCv[CCN].size(); i++) {
    int v = CCv[CCN][i];
    d[CCN].push_back(max(bfsd[0][v], bfsd[1][v]));
  }
  sort(d[CCN].begin(), d[CCN].end());
  dd[CCN].push_back(d[CCN][0]);
  for (int i = 1; i < (int)d[CCN].size(); i++)
    dd[CCN].push_back(dd[CCN][i - 1] + d[CCN][i]);
  CCN++;
}
map<int, double> memo[MAXN];
int main() {
  scanf("%d", &N), scanf("%d", &M);
  scanf("%d", &Q);
  for (int i = 0; i < (int)M; i++) {
    int v, u;
    scanf("%d", &v), scanf("%d", &u);
    v--;
    u--;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  memset(CC, -1, sizeof(CC));
  for (int v = 0; v < (int)N; v++)
    if (CC[v] == -1) makeCC(v);
  for (int i = 0; i < (int)Q; i++) {
    int V, U;
    scanf("%d", &V), scanf("%d", &U);
    V--;
    U--;
    V = CC[V];
    U = CC[U];
    if (V == U) {
      printf("-1\n");
      continue;
    }
    int sU = d[U].size(), sV = d[V].size();
    if (sU > sV) {
      swap(sU, sV);
      swap(U, V);
    }
    if (memo[U].count(V)) {
      printf("%.16lf\n", memo[U][V]);
      continue;
    }
    double ans = 1.0 * dd[U][sU - 1] / sU + 1.0 * dd[V][sV - 1] / sV + 1;
    for (int i = 0; i < (int)d[U].size(); i++) {
      int du = d[U][i], di = max(diam[U], diam[V]);
      int x = distance(d[V].begin(),
                       upper_bound(d[V].begin(), d[V].end(), di - du - 2));
      if (x < 1) continue;
      ans -= 1.0 * (du * x + dd[V][x - 1] + x) / (1.0 * sU * sV);
      ans += 1.0 * di * x / (1.0 * sU * sV);
    }
    memo[U][V] = ans;
    printf("%.16lf\n", ans);
  }
}
