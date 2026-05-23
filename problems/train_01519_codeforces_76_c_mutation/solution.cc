#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
template <typename T>
inline int ts(T *s) {
  int a = 0, c = fetch();
  while (c <= 32 && c != EOF) c = fetch();
  while (c > 32 && c != EOF) s[a++] = c, c = fetch();
  s[a] = 0;
  return a;
}
}  // namespace ae86
using ae86::ts;
using ae86::ty;
const int _ = 200007, alp = 22, __ = 4233333;
int n, ps, str[_], ned[alp], val[alp][alp];
long long lim, f[__] = {0};
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), ps = ty(), lim = ty(), ts(str + 1);
  for (int i = 0; i < ps; i++) ned[i] = ty();
  for (int i = 0; i < ps; i++)
    for (int j = 0; j < ps; j++) val[i][j] = ty();
  for (int i = 1; i <= n; i++) str[i] -= 'A';
  int las[alp];
  memset(las, -1, sizeof(las));
  int all = 0;
  for (int i = 0; i < ps; i++) f[(1 << (i))] = ned[i];
  for (int i = 1; i <= n; i++) {
    all |= (1 << (str[i]));
    for (int j = 0; j < ps; j++) {
      if (las[j] < 0) continue;
      if (!(((las[j]) >> (j)) & 1) && !(((las[j]) >> (str[i])) & 1)) {
        f[las[j]] += val[j][str[i]];
        f[las[j] | (1 << (j))] -= val[j][str[i]];
        f[las[j] | (1 << (str[i]))] -= val[j][str[i]];
        f[las[j] | (1 << (j)) | (1 << (str[i]))] += val[j][str[i]];
      }
      las[j] |= (1 << (str[i]));
    }
    las[str[i]] = 0;
  }
  for (int i = 0; i < alp; i++)
    for (int j = 0; j < (1 << (alp)); j++)
      if ((((j) >> (i)) & 1)) f[j] += f[j - (1 << (i))];
  int ans = 0;
  for (int i = 0; i < (1 << (alp)); i++)
    if ((i & all) == i && i != all && f[i] <= lim) ans++;
  cout << ans << lf;
  return 0;
}
