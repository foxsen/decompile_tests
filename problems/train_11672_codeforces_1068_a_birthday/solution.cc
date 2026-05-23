#include <bits/stdc++.h>
long long n, m, k, l;
long long ans;
int main() {
  scanf("%lld%lld%lld%lld", &n, &m, &k, &l);
  ans = (l + k) / m;
  if ((l + k) % m != 0) ++ans;
  if (ans * m > n)
    puts("-1");
  else
    printf("%lld\n", ans);
}
