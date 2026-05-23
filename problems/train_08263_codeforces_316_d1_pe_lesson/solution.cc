#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, P = 1e9 + 7;
int t, n, tt[N], cnt, tmp;
long long sum, f[N], fac[N];
void freo() {
  freopen("throw.in", "r", stdin);
  freopen("throw.out", "w", stdout);
}
void prep() {
  t = 1;
  f[1] = fac[0] = 1;
  f[2] = 2;
  for (int i = 0; ++i < N; fac[i] = fac[i - 1] * i % P)
    ;
  for (int i = 2; ++i < N; f[i] = (f[i - 1] + f[i - 2] * (i - 1) % P) % P)
    ;
}
void init() {
  scanf("%d", &n);
  tmp = 0;
  for (int i = 0; ++i <= n; scanf("%d", &tt[i]), tmp += tt[i])
    ;
  tmp -= n;
  cnt = n - tmp;
}
void work() {
  if (!cnt) {
    sum = fac[tmp];
    return;
  }
  sum = f[cnt];
  ++cnt;
  for (int i = 0; ++i <= tmp; sum = sum * cnt % P, ++cnt)
    ;
}
void prin() { printf("%lld\n", sum); }
int main() {
  for (prep(); t--; init(), work(), prin())
    ;
  return 0;
}
