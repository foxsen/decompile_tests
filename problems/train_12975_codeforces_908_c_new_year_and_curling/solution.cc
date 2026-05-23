#include <bits/stdc++.h>
using namespace std;
int n, r, x[1005];
double ans[1005];
int main() {
  cin >> n >> r;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) {
    ans[i] = r;
    for (int j = 1; j < i; j++) {
      if (abs(x[i] - x[j]) > 2 * r) continue;
      ans[i] = max(ans[i], ans[j] + sqrt(4.0 * r * r - 1.0 * abs(x[i] - x[j]) *
                                                           abs(x[i] - x[j])));
    }
  }
  for (int i = 1; i <= n; i++)
    cout << fixed << setprecision(9) << ans[i] << ' ';
}
