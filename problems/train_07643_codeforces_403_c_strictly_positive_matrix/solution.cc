#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> adj[2005];
int num[2005], low[2005], cnt;
void dfs(int u) {
  low[u] = num[u] = ++cnt;
  for (int i = (0), _b = ((int)adj[u].size() - 1); i <= _b; i++) {
    int v = adj[u][i];
    if (num[v])
      low[u] = min(low[u], num[v]);
    else {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
  }
  if (u != 1 && num[u] == low[u]) {
    cout << "NO" << endl;
    exit(0);
  }
}
int main(void) {
  scanf("%d", &N);
  char x = getchar();
  for (int i = (1), _b = (N); i <= _b; i++)
    for (int j = (1), _b = (N); j <= _b; j++) {
      while ('0' <= x && x <= '9') x = getchar();
      x = getchar();
      if (x != '0') adj[i].push_back(j);
    }
  dfs(1);
  for (int i = (1), _b = (N); i <= _b; i++)
    if (!num[i]) return cout << "NO" << endl, 0;
  cout << "YES" << endl;
  return 0;
}
