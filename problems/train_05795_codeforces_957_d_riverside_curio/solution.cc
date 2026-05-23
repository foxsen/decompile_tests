#include <bits/stdc++.h>
using namespace std;
int n, m[100005], a[100005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    m[i] = a[i] + 1;
  }
  long long ans = 0;
  for (int i = n - 1; i >= 1; --i) m[i] = max(m[i], m[i + 1] - 1);
  for (int i = 1; i <= n; ++i) m[i] = max(m[i], m[i - 1]);
  for (int i = 1; i <= n; ++i) ans += (m[i] - a[i] - 1);
  cout << ans << endl;
  return 0;
}
