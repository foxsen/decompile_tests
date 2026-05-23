#include <bits/stdc++.h>
using namespace std;
int r[100005], l[100005];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &l[i], &r[i]);
  sort(l, l + n);
  sort(r, r + n);
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += max(l[i], r[i]);
  }
  cout << ans + n << endl;
  return 0;
}
