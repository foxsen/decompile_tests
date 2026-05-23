#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int mod = 998244353;
int T;
int a[N], b[N], p[N];
bool vis[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      p[a[i]] = i;
      vis[i] = 0;
    }
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &b[i]);
    }
    int ans = 1;
    for (int i = k; i >= 1; --i) {
      int t = p[b[i]];
      int kk = 0;
      if (t > 1 && !vis[t - 1]) kk++;
      if (t < n && !vis[t + 1]) kk++;
      vis[t] = 1;
      ans = (ans * kk) % mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}
