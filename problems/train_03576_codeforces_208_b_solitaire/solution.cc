#include <bits/stdc++.h>
using namespace std;
char card[53][5];
short f[53][53][53][53];
int n;
bool check(int a, int b) {
  return card[a][0] == card[b][0] || card[a][1] == card[b][1];
}
bool dfs(int N, int a, int b, int c) {
  short &res = f[N][a][b][c];
  if (N == 1) return true;
  if (res != -1) return res;
  if (check(b, c) && dfs(N - 1, N - 3, a, c)) return res = 1;
  if (N - 3 && check(N - 3, c) && dfs(N - 1, c, a, b)) return res = 1;
  res = 0;
  return false;
}
int main(int argc, char *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", card[i]);
  }
  memset(f, -1, sizeof(f));
  dfs(n, n - 2, n - 1, n);
  puts(f[n][n - 2][n - 1][n] ? "YES" : "NO");
  return 0;
}
