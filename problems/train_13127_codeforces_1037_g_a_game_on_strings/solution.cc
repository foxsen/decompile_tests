#include <bits/stdc++.h>
using namespace std;
struct pat {
  int x, y;
  pat(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(const pat &p) const { return x == p.x ? y < p.y : x < p.x; }
};
namespace RKK {
const int N = 100011;
int n, qaq;
char str[N];
int s[N];
int nxt[N][26], pre[N][26];
int f[N][26], g[N];
int mp[27];
int dfs(int l, int r, int c, int tp) {
  if (l > r) return 0;
  if (~mp[c]) return mp[c];
  int mex[50] = {0};
  for (int i = 0, pl, pr; i < 26; i++) {
    pl = nxt[l - 1][i], pr = pre[r + 1][i];
    if (pr < l) continue;
    int t = g[pl] ^ g[pr];
    t ^= tp ? f[pl - 1][c] : dfs(l, pl - 1, i, 0);
    t ^= tp ? dfs(pr + 1, r, i, 1) : f[r][i];
    mex[t] = 1;
  }
  for (int i = 0; i < 50; i++)
    if (!mex[i]) return mp[c] = i;
  return -1;
}
int main() {
  scanf("%s", str + 1), n = strlen(str + 1);
  for (int i = 1; i <= n; i++) s[i] = str[i] - 'a';
  for (int i = 0; i < 26; i++) pre[1][i] = 0;
  for (int i = 2; i <= n + 1; i++)
    memcpy(pre[i], pre[i - 1], 26 * 4), pre[i][s[i - 1]] = i - 1;
  for (int i = 0; i < 26; i++) nxt[n][i] = n + 1;
  for (int i = n - 1; ~i; i--)
    memcpy(nxt[i], nxt[i + 1], 26 * 4), nxt[i][s[i + 1]] = i + 1;
  for (int i = 1; i <= n; i++) {
    g[i] = g[pre[i][s[i]]] ^ f[i - 1][s[i]];
    memset(mp, 0xff, sizeof(mp));
    for (int j = 0; j < 26; j++) f[i][j] = dfs(pre[i + 1][j] + 1, i, j, 1);
  }
  scanf("%d", &qaq);
  for (int rkk = 1, l, r; rkk <= qaq; rkk++) {
    scanf("%d%d", &l, &r);
    memset(mp, 0xff, sizeof(mp));
    puts(dfs(l, r, 26, 0) ? "Alice" : "Bob");
  }
  return 0;
}
}  // namespace RKK
int main() { return RKK::main(); }
