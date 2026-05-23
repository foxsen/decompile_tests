#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
const int M = 123;
const double Pi = acos(-1);
const long long Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) { return 1ll * a * b % mod; }
int n, m, t[2][2][N][N];
int get(int x, int y) {
  int ans = 0;
  for (int i = x; i > 0; i = (i & (i + 1)) - 1) {
    for (int j = y; j > 0; j = (j & (j + 1)) - 1) {
      ans ^= t[x & 1][y & 1][i][j];
    }
  }
  return ans;
}
void upd(int x, int y, int v) {
  for (int i = x; i <= n; i = (i | (i + 1))) {
    for (int j = y; j <= n; j = (j | (j + 1))) {
      t[x & 1][y & 1][i][j] ^= v;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int it = 0; it < m; it++) {
    int t, x1, y1, x2, y2, v;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
    if (t == 1) {
      int ans =
          get(x2, y2) ^ get(x1 - 1, y1 - 1) ^ get(x1 - 1, y2) ^ get(x2, y1 - 1);
      printf("%d\n", ans);
    } else {
      scanf("%d", &v);
      upd(x1, y1, v);
      upd(x2 + 1, y1, v);
      upd(x1, y2 + 1, v);
      upd(x2 + 1, y2 + 1, v);
    }
  }
  return 0;
}
