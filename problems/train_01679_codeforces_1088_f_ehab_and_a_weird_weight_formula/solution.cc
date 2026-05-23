#include <bits/stdc++.h>
using namespace std;
int n, A[(1001010)], rt, f[(1001010)][40];
vector<int> Vec[(1001010)];
long long ans;
void Dfs(int x) {
  for (int i = 0; i < Vec[x].size(); i++) {
    int y = Vec[x][i];
    if (y == f[x][0]) continue;
    f[y][0] = x;
    Dfs(y);
  }
}
long long Lmin(long long a, long long b) {
  if (a < b) return a;
  return b;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  rt = 1;
  for (int i = 2; i <= n; i++)
    if (A[i] < A[rt]) rt = i;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    Vec[x].push_back(y);
    Vec[y].push_back(x);
  }
  Dfs(rt);
  f[rt][0] = rt;
  for (int j = 1; j <= 30; j++)
    for (int i = 1; i <= n; i++) f[i][j] = f[f[i][j - 1]][j - 1];
  for (int i = 1; i <= n; i++)
    if (i != rt) {
      long long Min = (long long)A[f[i][0]] + (long long)A[i];
      for (int k = 1; k <= 30; k++)
        Min = Lmin(Min, (long long)k * (long long)min(A[i], A[f[i][k]]) +
                            (long long)(A[i] + A[f[i][k]]));
      ans += Min;
    }
  cout << ans;
}
