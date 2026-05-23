#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const long long mod = 998244353;
int a[maxn], aa[maxn];
bool used[maxn];
int b[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    memset(used, 1, sizeof(used));
    used[0] = used[n + 1] = false;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      b[a[i]] = i;
    }
    long long ans = 1;
    for (int i = 1; i <= m; ++i) {
      scanf("%d", aa + i);
      used[b[aa[i]]] = false;
    }
    for (int i = 1, l, pos, z; i <= m; ++i) {
      l = aa[i];
      pos = b[l];
      z = used[pos - 1] + used[pos + 1];
      ans = ans * z % mod;
      used[pos] = true;
    }
    cout << ans << endl;
  }
  return 0;
}
