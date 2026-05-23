#include <bits/stdc++.h>
using namespace std;
const int Mn = 1e5 + 5;
struct A {
  long long a;
  bool x;
} p[Mn << 1];
int cnt = 0;
bool cmp(A a, A b) {
  if (a.a != b.a) return a.a < b.a;
  return a.x < b.x;
}
int main() {
  int n;
  scanf("%d", &n);
  long long x, y;
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &x, &y);
    p[++cnt].a = x;
    p[cnt].x = 1;
    p[++cnt].a = y;
    p[cnt].x = 0;
  }
  long long ans = 0;
  long long mx = -1;
  sort(p + 1, p + 1 + cnt, cmp);
  long long t = 0;
  for (int i = 1; i <= cnt; i++) {
    if (p[i].x)
      t++;
    else
      t--;
    if (t > mx) {
      ans = p[i].a;
      mx = t;
    }
  }
  printf("%lld %lld\n", ans, mx);
  return 0;
}
