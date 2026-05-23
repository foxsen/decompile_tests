#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long MOD) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
struct Point {
  int x, y;
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  void mov() { x--, y++; }
  bool operator==(const Point &o) const { return x == o.x && y == o.y; }
};
int n, m;
const int N = 500 + 5;
char s[N][N];
int dp[2][N][N];
const int MOD = 1e9 + 7;
inline void addmod(int &a, int b) { a = (a + b) % MOD; }
void nxt1(Point &a) { a.x++; }
void nxt2(Point &a) { a.y--; }
bool eq(Point &a, Point &b) { return s[a.x][a.y] == s[b.x][b.y]; }
bool valid(Point &a) { return a.x >= 1 && a.x <= n && a.y >= 1 && a.y <= m; }
bool adj(Point &a, Point &b) {
  return abs(a.x - b.x) <= 1 && abs(a.y - b.y) <= 1;
}
int main() {
  scanf("%d%d", &n, &m);
  getchar();
  for (int i = 1; i <= n; i++) {
    gets(s[i] + 1);
  }
  Point st1(1, 1), st2(n, m);
  dp[0][1][1] = 1;
  int cur = 1, pre = 0, ans = 0;
  for (int l = 2, r = n + m; l <= r; l++, r--) {
    Point a = st1, b = st2;
    for (int i = 1; i < l; i++, a.mov()) {
      if (!valid(a)) continue;
      b = st2;
      for (int j = 1; j < l; j++, b.mov()) {
        if (!valid(b)) continue;
        if (eq(a, b)) {
          addmod(dp[cur][i][j], (0LL + dp[pre][i][j] + dp[pre][i - 1][j] +
                                 dp[pre][i][j - 1] + dp[pre][i - 1][j - 1]) %
                                    MOD);
          if (l == r - 1 && adj(a, b)) {
            addmod(ans, dp[cur][i][j]);
          } else if (l == r && a == b) {
            addmod(ans, dp[cur][i][j]);
          }
        }
      }
    }
    nxt1(st1);
    nxt2(st2);
    memset(dp[pre], 0, sizeof dp[pre]);
    swap(cur, pre);
  }
  printf("%d\n", ans);
  return 0;
}
