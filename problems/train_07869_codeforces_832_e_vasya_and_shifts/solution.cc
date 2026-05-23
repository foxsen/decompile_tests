#include <bits/stdc++.h>
using namespace std;
void read_file(bool outToFile = true) {}
const int MAXN = 500 + 99;
int n, m, nq;
char str[MAXN];
int A[MAXN][MAXN], B[MAXN];
int mod_inv[] = {0, 1, 3, 2, 4};
int num;
void swapp(int i, int j) {
  for (int k = 0; k < m; k++) swap(A[i][k], A[j][k]);
}
inline void fix(int &x) {
  x %= 5;
  if (x < 0) x += 5;
}
void debug() {
  printf("...\n");
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) printf("%d%c", A[i][j], " \n"[j == 0]);
  }
  printf("...\n");
}
void gauss() {
  int cur = 0;
  for (int i = m - 1; i >= 0; i--) {
    bool fnd = false;
    for (int j = cur; j < n; j++) {
      if (A[j][i] != 0) {
        swapp(j, cur);
        fnd = true;
        break;
      }
    }
    if (!fnd) {
      continue;
    }
    int x = A[cur][i];
    for (int j = cur + 1; j < n; j++) {
      int y = A[j][i];
      int a = y * mod_inv[x] % 5;
      for (int k = 0; k < m; k++) {
        A[j][k] = A[j][k] - a * A[cur][k];
        fix(A[j][k]);
      }
    }
    cur++;
  }
  int itr = n - cur;
  num = 1;
  for (int i = 0; i < itr; i++) num = num * 5LL % (1000000007);
}
bool can() {
  int cur = 0;
  for (int i = m - 1; i >= 0; i--) {
    if (B[i] == 0) {
      if (A[cur][i] != 0) cur++;
      continue;
    }
    while (cur < n && A[cur][i] == 0) cur++;
    if (cur == n) return false;
    int x = A[cur][i];
    int y = B[i];
    int a = y * mod_inv[x] % 5;
    for (int k = 0; k < m; k++) {
      B[k] = B[k] - a * A[cur][k];
      fix(B[k]);
    }
    cur++;
  }
  return true;
}
int main() {
  read_file();
  while (scanf("%d%d", &n, &m) != -1) {
    for (int i = 0; i < n; i++) {
      scanf("%s", str);
      for (int j = 0; j < m; j++) A[i][j] = str[j] - 'a';
    }
    gauss();
    scanf("%d", &nq);
    while (nq--) {
      scanf("%s", str);
      for (int j = 0; j < m; j++) B[j] = str[j] - 'a';
      int ans = can() ? num : 0;
      printf("%d\n", ans);
    }
  }
}
