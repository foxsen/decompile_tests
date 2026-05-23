#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 3;
int n, m, par[Maxn];
vector<pair<int, int> > v[Maxn];
bool mark[Maxn], marke[Maxn];
void dfs(int e, int st) {
  mark[st] = 1;
  queue<int> q;
  for (int i = 0; i < v[st].size(); ++i) {
    int nxt = v[st][i].first, id = v[st][i].second;
    if (!mark[nxt]) {
      par[nxt] = st;
      dfs(id, nxt);
      if (!marke[id]) {
        q.push(nxt);
        marke[id] = 1;
      }
    } else if (par[st] != nxt && !marke[id]) {
      marke[id] = 1;
      q.push(nxt);
    }
  }
  if (q.size() % 2) {
    marke[e] = 1;
    q.push(par[st]);
  }
  while (!q.empty()) {
    printf("%d %d ", q.front(), st);
    q.pop();
    printf("%d\n", q.front());
    q.pop();
  }
}
int main() {
  scanf("%d%d", &n, &m);
  if (m % 2) {
    printf("No solution\n");
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(make_pair(b, i));
    v[b].push_back(make_pair(a, i));
  }
  dfs(1e9, 1);
  return 0;
}
