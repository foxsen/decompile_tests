#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int n, flg = 1, tot;
basic_string<int> v[1 << 17];
void dfs(int p, int f = 0, int dep = 1) {
  int fs = 1;
  for (int i : v[p])
    if (i != f) {
      if (v[i].size() == 1) {
        if (fs) fs = 0, tot += dep != 2;
      } else
        tot++;
      if (v[i].size() == 1 && (dep & 1)) flg = 0;
      dfs(i, p, dep + 1);
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x] += y, v[y] += x;
  }
  for (int i = 1; i <= n; i++)
    if (v[i].size() == 1) {
      dfs(i);
      printf("%d %d\n", flg ? 1 : 3, tot);
      break;
    }
  return 0;
}
