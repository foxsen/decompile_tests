#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const long long Linf = (1uLL << 63) - 1;
const double EPS = 1e-10;
namespace IOSpace {
void get_int(int &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-'; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
}
void get_int(long long &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-'; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
}
void print_int(int x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
void print_int(long long x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
}  // namespace IOSpace
using namespace IOSpace;
const int maxn = 253;
const int maxlog = 20;
const long long mod = 1000000007;
char s[maxn][maxn];
int n, m, ans, cnt;
pair<int, int> q[maxn * maxn], down;
int use[maxn][maxn], kk;
void dfs(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '0' || use[x][y]) return;
  use[x][y] = kk;
  ++cnt;
  down = max(down, make_pair(x, y));
  dfs(x - 1, y - 1);
  dfs(x - 1, y + 1);
  dfs(x + 1, y - 1);
  dfs(x + 1, y + 1);
  dfs(x - 1, y);
  dfs(x + 1, y);
  dfs(x, y - 1);
  dfs(x, y + 1);
}
void solve() {
  ans = kk = 0;
  get_int(n), get_int(m);
  memset((use), (0), sizeof(use));
  int len, ok;
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!use[i][j] && s[i][j] == '1') {
        kk++;
        cnt = 0;
        down = make_pair(-1, -1);
        dfs(i, j);
        if (down.first == i) continue;
        if (down.second == j && ((down.first - i) & 1) == 0) {
          len = down.first - i;
          if (len << 1 != cnt) continue;
          ok = 1;
          for (int ii = 0; ii + ii <= len && ok; ii++) {
            ok &= (j - ii >= 0 && use[i + ii][j - ii] == kk &&
                   use[down.first - ii][j - ii] == kk);
            ok &= (j + ii < m && use[i + ii][j + ii] == kk &&
                   use[down.first - ii][j + ii] == kk);
          }
          ans += ok;
        } else if (down.second - j == down.first - i) {
          len = down.first - i;
          if (len << 2 != cnt) continue;
          ok = 1;
          for (int ii = 0; ii <= len && ok; ii++) {
            ok &= use[i][j + ii] == kk;
            ok &= use[down.first][j + ii] == kk;
            ok &= use[i + ii][j] == kk;
            ok &= use[i + ii][down.second] == kk;
          }
          ans += ok;
        }
      }
  printf("%d\n", ans);
}
int main() {
  int T;
  get_int(T);
  while (T--) solve();
  return 0;
}
