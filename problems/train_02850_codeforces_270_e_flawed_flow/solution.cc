#include <bits/stdc++.h>
using namespace std;
int inflow[200005], outflow[200005], cost[200005], A[200005], B[200005];
int ans[200005];
vector<pair<int, int> > adj[200005];
vector<pair<int, int> >::iterator it;
int main() {
  memset(ans, -1, sizeof(ans));
  int N, M;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d%d%d", &a, &b, &cost[i]);
    adj[a].push_back(make_pair(b, i));
    adj[b].push_back(make_pair(a, i));
    outflow[a] += cost[i];
    outflow[b] += cost[i];
    A[i] = a;
    B[i] = b;
  }
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (it = adj[x].begin(); it != adj[x].end(); ++it) {
      int y = it->first, id = it->second;
      if (ans[id] != -1) continue;
      ans[id] = (A[id] == x) ? 0 : 1;
      inflow[y] += cost[id];
      outflow[y] -= cost[id];
      if (inflow[y] == outflow[y] && y != N) Q.push(y);
    }
  }
  for (int i = 0; i < M; ++i) printf("%d\n", ans[i]);
}
