#include <bits/stdc++.h>
using namespace std;
int n, q, ans[50005], sum[50005], a[50005], p[50005], x[50005], cont, pos,
    us[50005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) cin >> p[i];
  for (int i = 0; i < q; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) {
    pos = i;
    cont = 1;
    while (pos != 1) {
      us[pos] = cont;
      cont++;
      pos = p[pos];
    }
    us[pos] = cont;
    for (int j = 0; j < q; j++) {
      if (us[x[j]]) {
        ans[j]++;
        sum[j] += us[x[j]];
        j += a[i] - 1;
      }
    }
    pos = i;
    cont = 1;
    while (pos != 1) {
      us[pos] = 0;
      cont++;
      pos = p[pos];
    }
    us[pos] = 0;
  }
  for (int i = 0; i < q; i++) cout << sum[i] - ans[i] << " " << ans[i] << "\n";
  return 0;
}
