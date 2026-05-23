#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long f[2005][2005], n, k;
vector<int> u[2005];
void U() {
  for (int i = 1; i < 2005; i++) {
    for (int j = 1; j <= i; j++)
      if (i % j == 0) u[i].push_back(j);
  }
}
int main() {
  ios::sync_with_stdio(false);
  U();
  cin >> n >> k;
  memset(f, 0, sizeof f);
  for (int i = 1; i < 2005; i++) f[1][i] = 1;
  for (int l = 2; l <= k; l++)
    for (int x = 1; x <= n; x++) {
      for (unsigned i = 0; i < u[x].size(); i++)
        f[l][x] = (f[l][x] + f[l - 1][u[x][i]]) % MOD;
    }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + f[k][i]) % MOD;
  cout << ans;
}
