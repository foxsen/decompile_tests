#include <bits/stdc++.h>
using namespace std;
int route[1005], d[305], k[305], pre[305], p[305];
vector<int> v[305];
int cnt = 0;
void dfs(int i, int f) {
  for (int j = 0; j < v[i].size(); j++) {
    if (v[i][j] != f) {
      pre[v[i][j]] = i;
      dfs(v[i][j], i);
    }
  }
}
int solve(int k1, int k2, int t) {
  int j = 0, sign = 0;
  p[j++] = k1;
  while (pre[k1]) {
    k1 = pre[k1];
    p[j++] = k1;
    if (k1 == k2) {
      sign = 1;
      break;
    }
  }
  if (sign == 0) return 0;
  if (t == 1) {
    for (int i = 0; i < j; i++) {
      route[cnt++] = p[i];
    }
  } else {
    for (int i = j - 1; i >= 0; i--) {
      route[cnt++] = p[i];
    }
  }
  return 1;
}
int main() {
  int n, a, b;
  scanf("%d", &n);
  memset(d, -1, sizeof(d));
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &a, &b);
    d[a]++;
    d[b]++;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  d[1]++;
  dfs(1, -1);
  int e = 0;
  while (1) {
    scanf("%d", k + e);
    e++;
    if (getchar() == '\n') break;
  }
  solve(k[0], 1, 2);
  for (int i = 1; i < e; i++) {
    int m = k[i - 1];
    while (1) {
      m = pre[m];
      d[m]--;
      if (d[m] > 0) break;
    }
    solve(k[i - 1], m, 1);
    if (solve(k[i], m, 2) == 0) {
      puts("-1");
      return 0;
    }
  }
  solve(k[e - 1], 1, 1);
  printf("%d", route[0]);
  for (int i = 1; i < cnt; i++) {
    if (route[i] != route[i - 1]) {
      printf(" %d", route[i]);
    }
  }
  return 0;
}
