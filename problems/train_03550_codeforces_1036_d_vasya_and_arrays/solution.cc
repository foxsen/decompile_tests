#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const long long INF = 1e9 + 7;
const int N = 5e5 + 10;
long long a[N];
long long b[N];
int main() {
  int n;
  int m;
  scanf("%d", &n);
  map<long long, int> mc;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i] += a[i - 1];
    mc[a[i]] = 1;
  }
  scanf("%d", &m);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    b[i] += b[i - 1];
    if (mc.count(b[i])) ans++;
  }
  if (b[m] != a[n]) ans = -1;
  printf("%d\n", ans);
  return 0;
}
