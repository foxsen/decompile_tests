#include <bits/stdc++.h>
using namespace std;
namespace zzc {
const int maxn = 5e5 + 5;
long long c[maxn], a[maxn], l[maxn], r[maxn];
long long t, n;
long long lowbit(long long x) { return x & (-x); }
void update(long long pos, long long k) {
  for (long long i = pos; i <= n; i += lowbit(i)) {
    c[i] += k;
  }
}
long long query(long long pos) {
  long long res = 0;
  for (long long i = pos; i; i -= lowbit(i)) {
    res += c[i];
  }
  return res;
}
void work() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (a[i] * 2 - 1 <= n)
      l[i] = query(a[i] * 2 - 1);
    else
      l[i] = query(n) - query(2 * a[i] - n - 1);
    update(a[i], a[i]);
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] * 2 - 1 <= n)
      r[i] = query(a[i] * 2 - 1);
    else
      r[i] = query(n) - query(a[i] * 2 - n - 1);
    update(a[i], a[i]);
  }
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    if (l[i] && r[i] && l[i] % (2 * a[i]) && r[i] % (2 * a[i])) {
      flag = true;
      printf("YES\n");
      break;
    }
  }
  if (!flag) printf("NO\n");
}
}  // namespace zzc
int main() {
  zzc::work();
  return 0;
}
