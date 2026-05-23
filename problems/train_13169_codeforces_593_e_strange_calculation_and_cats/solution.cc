#include <bits/stdc++.h>
using namespace std;
const int N = 22;
int n, m, q, last, vi[N][N];
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
inline void add(int &a, int b) {
  a = ((a + b >= 1000000007) ? a + b - 1000000007 : a + b);
}
inline void del(int &a, int b) {
  a = ((a - b < 0) ? a - b + 1000000007 : a - b);
}
inline void mul(int &a, int b) { a = 1ll * a * b % 1000000007; }
inline int id(int x, int y) { return (x - 1) * m + y; }
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
struct matrix {
  int n, a[N][N];
  inline void clear() { memset(a, 0, sizeof(a)); }
  inline void init() {
    for (int i = 1; i <= n; i++) a[i][i] = 1;
  }
  inline void print() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) printf("%d ", a[i][j]);
      printf("\n");
    }
  }
} f;
matrix tr;
matrix operator*(matrix a, matrix b) {
  matrix ans;
  ans.n = a.n;
  ans.clear();
  for (int i = 1; i <= a.n; i++) {
    for (int k = 1; k <= a.n; k++) {
      for (int j = 1; j <= a.n; j++)
        add(ans.a[i][j], 1ll * a.a[i][k] * b.a[k][j] % 1000000007);
    }
  }
  return ans;
}
matrix m_pow(matrix a, int b) {
  matrix ans;
  ans.n = a.n;
  ans.clear();
  ans.init();
  while (b) {
    if (b & 1) ans = ans * a;
    b >>= 1;
    a = a * a;
  }
  return ans;
}
inline void get() {
  tr.clear();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vi[i][j]) continue;
      tr.a[id(i, j)][id(i, j)] = 1;
      for (int k = 1; k <= 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x <= 0 || y <= 0 || x > n || y > m || vi[x][y]) continue;
        tr.a[id(i, j)][id(x, y)] = 1;
      }
    }
  }
}
signed main() {
  n = read();
  m = read();
  q = read();
  last = 1;
  f.n = tr.n = n * m;
  f.a[1][1] = 1;
  get();
  while (q--) {
    int op = read(), x = read(), y = read(), t = read();
    f = f * m_pow(tr, t - last);
    last = t;
    if (op == 2) vi[x][y] = 1;
    if (op == 3) vi[x][y] = 0;
    if (op == 1) printf("%d\n", f.a[1][id(x, y)]);
    get();
  }
}
