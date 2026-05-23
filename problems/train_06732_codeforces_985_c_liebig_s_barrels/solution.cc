#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
int main() {
  int n, k, l;
  scanf("%d %d %d", &n, &k, &l);
  for (int i = 1; i <= n * k; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n * k);
  int idx = upper_bound(a + 1, a + 1 + n * k, a[1] + l) - a;
  int num = idx - 1;
  if (num < n) {
    puts("0");
    return 0;
  } else {
    long long ans = 0;
    int now = 1;
    for (int i = 1; i <= n; i++) {
      ans += a[now];
      now++;
      int left = num - now + 1;
      int have = 1;
      while (have < k && left > n - i) now++, left--, have++;
    }
    cout << ans << endl;
  }
}
