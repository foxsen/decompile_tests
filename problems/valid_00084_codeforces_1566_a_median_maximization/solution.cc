#include <bits/stdc++.h>
using namespace std;
long long t, n, s;
bool check(long long mid) {
  long long ls = n / 2, rs = n / 2;
  if (n % 2 == 0) {
    ls--;
  }
  long long down = ls * 0 + rs * mid + mid;
  if (down <= s) return true;
  return false;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &s);
    long long l = 0, r = s, ans = 0;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (check(mid))
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
