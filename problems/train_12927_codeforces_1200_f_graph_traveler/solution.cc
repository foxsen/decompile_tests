#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 10, N = 2520;
int n, k[M], ans[M][N + 5], tim[M], dep;
vector<int> vt[M];
int dfs(int x, int y) {
  if (ans[x][y] > 0) return ans[x][y];
  if (ans[x][y] < 0) {
    int siz = 0;
    for (int i = 1; i <= n; i++)
      if (tim[i] <= ans[x][y]) siz++;
    return siz;
  }
  ans[x][y] = tim[x] = --dep;
  int val = (y + k[x] % N + N) % N, nxt = vt[x][val % vt[x].size()];
  return ans[x][y] = dfs(nxt, val);
}
int main(int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
  for (int i = 1; i <= n; i++) {
    int m;
    scanf("%d", &m);
    for (int j = 1; j <= m; j++) {
      int x;
      scanf("%d", &x);
      vt[i].push_back(x);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", dfs(x, (y % N + N) % N));
  }
  return 0;
}
