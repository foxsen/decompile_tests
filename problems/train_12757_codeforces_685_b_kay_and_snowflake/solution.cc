#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
vector<int> m[300100], q[300100];
int r[300100], h[300100], z[300100], c[300100], p[300100];
void dfs(int i) {
  h[i] = 1;
  z[i] = 0;
  for (int j = 0; j < m[i].size(); j++) {
    dfs(m[i][j]);
    h[i] += h[m[i][j]];
    z[i] = max(z[i], h[m[i][j]]);
  }
  if (z[i] <= h[i] / 2)
    c[i] = i;
  else {
    for (int j = 0; j < m[i].size(); j++) {
      int a = c[m[i][j]];
      for (; a != i; a = p[a])
        if (z[a] <= h[i] / 2 && h[i] - h[a] <= h[i] / 2) break;
      if (a != i) {
        c[i] = a;
        break;
      }
    }
  }
  for (int j = 0; j < q[i].size(); r[q[i][j]] = c[i], j++)
    ;
}
int main() {
  int n, nq, j;
  scanf("%d%d", &n, &nq);
  for (int i = 1; i < n; scanf("%d", &p[i]), p[i]--, m[p[i]].push_back(i), i++)
    ;
  for (int i = 0; i < nq; scanf("%d", &j), j--, q[j].push_back(i), i++)
    ;
  dfs(0);
  for (int i = 0; i < nq; printf("%d\n", r[i] + 1), i++)
    ;
  return 0;
}
