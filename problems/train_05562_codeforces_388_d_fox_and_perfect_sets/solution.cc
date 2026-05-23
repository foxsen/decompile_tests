#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long two[35];
int f[35][35][2], d[35];
int n, len;
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int dfs(int i, int j, int limit) {
  if (!i) return 1;
  if (f[i][j][limit] != -1) return f[i][j][limit];
  int res = 0;
  if (!limit) {
    res = add(res, two[j] * dfs(i - 1, j, 0) % mod);
    res = add(res, dfs(i - 1, j + 1, 0));
  } else {
    res = add(res, two[j == 0 ? 0 : j - 1] * dfs(i - 1, j, d[i] == 0) % mod);
    if (d[i]) {
      res = add(res, (j == 0 ? 0 : two[j - 1]) * dfs(i - 1, j, 1) % mod);
      res = add(res, dfs(i - 1, j + 1, 1));
    }
  }
  f[i][j][limit] = res;
  return res;
}
int main() {
  two[0] = 1;
  for (int i = 1; i < 32; i++) two[i] = add(two[i - 1], two[i - 1]);
  scanf("%d", &n);
  while (n) {
    d[++len] = n & 1;
    n >>= 1;
  }
  memset(f, -1, sizeof(f));
  printf("%d\n", dfs(len, 0, 1));
  return 0;
}
