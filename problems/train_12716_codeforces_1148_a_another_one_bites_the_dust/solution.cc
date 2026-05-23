#include <bits/stdc++.h>
using namespace std;
const long long INF = 0xacacaca;
inline long long read() {
  long long x = 0, f = 0;
  char ch = 0;
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) (x *= 10) += (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
long long a, b, c, ans;
signed main() {
  a = read();
  b = read();
  c = read();
  ans += c << 1;
  ans += min(a, b) * 2;
  ans += a == b ? 0 : 1;
  printf("%lld\n", ans);
  return 0;
}
