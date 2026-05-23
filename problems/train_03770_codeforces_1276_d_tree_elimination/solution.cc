#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, x, y;
vector<int> e[200005];
long long f[200005][4], pre[200005], nex[200005];
void DFS(int x, int p) {
  int fi = 0, y, k;
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] == p) {
      fi = i;
      break;
    }
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != p) DFS(e[x][i], x);
  f[x][0] = f[x][2] = pre[0] = 1;
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != p) {
      y = e[x][i];
      (f[x][0] *= (f[y][1] + f[y][2]) % 998244353) %= 998244353;
      if (i < fi) (f[x][2] *= (f[y][1] + f[y][2]) % 998244353) %= 998244353;
      if (i > fi)
        (f[x][2] *= (f[y][0] + f[y][1] + f[y][3]) % 998244353) %= 998244353;
      pre[i + 1] = ((f[y][1] + f[y][2]) % 998244353 * pre[i]) % 998244353;
    } else
      pre[i + 1] = pre[i];
  nex[e[x].size()] = 1;
  for (int i = e[x].size() - 1; i >= 0; i--)
    if (e[x][i] != p) {
      y = e[x][i];
      nex[i] =
          ((f[y][0] + f[y][1] + f[y][3]) % 998244353 * nex[i + 1]) % 998244353;
    } else
      nex[i] = nex[i + 1];
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != p) {
      y = e[x][i], k = (i < fi) ? 1 : 3;
      f[x][k] += (f[y][0] + f[y][3]) % 998244353 * pre[i] % 998244353 *
                 nex[i + 1] % 998244353;
    }
  f[x][1] %= 998244353, f[x][3] %= 998244353;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  DFS(1, 0);
  printf("%lld", (f[1][0] + f[1][1] + f[1][3]) % 998244353);
}
