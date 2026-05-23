#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
long long f[maxn][2][2];
int len;
char s[maxn];
long long dfs(int pos, int pre, int next) {
  if (f[pos][pre][next] != -1) return f[pos][pre][next];
  if (pos == (len + 1)) return next == 0;
  long long ans = 0;
  if (next == 0 && s[pos] == '*') return 0;
  if (next == 1 && s[pos] != '*' && s[pos] != '?') return 0;
  for (int i = 0; i <= 1; i++) {
    int nxt = i;
    if (s[pos] == '1' && (nxt + pre) != 1) continue;
    if (s[pos] == '2' && (nxt + pre) != 2) continue;
    if (s[pos] == '0' && (nxt + pre) != 0) continue;
    ans += dfs(pos + 1, next, nxt);
    ans %= mod;
  }
  f[pos][pre][next] = ans;
  return ans;
}
int main() {
  scanf("%s", s + 1);
  len = strlen(s + 1);
  memset(f, -1, sizeof f);
  cout << (dfs(1, 0, 0) + dfs(1, 0, 1)) % mod << endl;
  return 0;
}
