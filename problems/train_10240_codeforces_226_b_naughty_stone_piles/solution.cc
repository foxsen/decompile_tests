#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100100];
long long s[100100], pre;
int m, q;
void precalc() {
  pre = 0;
  for (int i = 1; i <= n; i++) pre += a[i] * (n - i);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  s[0] = 0;
  for (int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];
  precalc();
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    long long r = 0;
    scanf("%d", &q);
    if (q == 1) {
      printf("%I64d ", pre);
      continue;
    }
    long long k = q;
    int u = 1;
    long long last = n - 1;
    while (last > 0) {
      long long sum = s[last];
      if (last - k >= 0) sum -= s[last - k];
      r += sum * u;
      last = last - k;
      k *= q;
      u++;
    }
    printf("%I64d ", r);
  }
}
