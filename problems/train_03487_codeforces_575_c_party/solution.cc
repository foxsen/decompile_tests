#include <bits/stdc++.h>
bool used[21];
char P[21], way[21];
int n, m, res, U[21], V[21], minv[21], ar[21][21], fri[21][21], sat[21][21];
int hungarian(int i) {
  int j, i0, i1, j0, j1, cur, delta;
  P[0] = i, j0 = 0;
  for (j = 0; j <= m; j++) minv[j] = (1 << 27), used[j] = false;
  do {
    used[j0] = true;
    i0 = P[j0], j1 = 0, delta = (1 << 27);
    for (j = 1; j <= m; j++) {
      if (!used[j]) {
        cur = ar[i0][j] - U[i0] - V[j];
        if (cur < minv[j]) {
          minv[j] = cur;
          way[j] = j0;
        }
        if (minv[j] < delta) {
          delta = minv[j];
          j1 = j;
        }
      }
    }
    for (j = 0; j <= m; j++) {
      if (used[j]) {
        U[P[j]] += delta;
        V[j] -= delta;
      } else
        minv[j] -= delta;
    }
    j0 = j1;
  } while (P[j0] != 0);
  do {
    j1 = way[j0];
    P[j0] = P[j1];
    j0 = j1;
  } while (j0 != 0);
  return -V[0];
}
void backtrack(int i, int f, int s) {
  if (i == n) return;
  char C[21], D[21];
  int j, x, A[21], B[21];
  if (f) {
    for (j = 0; j <= m; j++)
      A[j] = U[j], B[j] = V[j], C[j] = P[j], D[j] = way[j];
    for (j = 0; j < m; j++) ar[i + 1][j + 1] = -fri[i][j];
    x = -hungarian(i + 1);
    backtrack(i + 1, f - 1, s);
    if (x > res) res = x;
    for (j = 0; j <= m; j++)
      U[j] = A[j], V[j] = B[j], P[j] = C[j], way[j] = D[j];
  }
  if (s) {
    for (j = 0; j <= m; j++)
      A[j] = U[j], B[j] = V[j], C[j] = P[j], D[j] = way[j];
    for (j = 0; j < m; j++) ar[i + 1][j + 1] = -sat[i][j];
    x = -hungarian(i + 1);
    backtrack(i + 1, f, s - 1);
    if (x > res) res = x;
    for (j = 0; j <= m; j++)
      U[j] = A[j], V[j] = B[j], P[j] = C[j], way[j] = D[j];
  }
}
int main() {
  int i, j, k, x;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &fri[i][j]);
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &sat[i][j]);
      }
    }
    res = 0, m = n;
    memset(way, 0, sizeof(way)), memset(U, 0, sizeof(U)),
        memset(V, 0, sizeof(V)), memset(P, 0, sizeof(P));
    backtrack(0, n >> 1, n >> 1);
    printf("%d\n", res);
  }
  return 0;
}
