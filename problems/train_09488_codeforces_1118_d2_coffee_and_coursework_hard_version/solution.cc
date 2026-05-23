#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
long long n, m;
long long a[N];
bool cmp(int a, int b) { return a > b; }
bool check(int x) {
  long long ans = 0, ct = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= ct) ans += ((long long)a[i] - ct);
    if (i % x == 0) ct++;
  }
  if (ans >= m) return true;
  return false;
}
int main() {
  while (~scanf("%d", &n)) {
    scanf("%d", &m);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    if (sum < m) {
      puts("-1");
      continue;
    }
    sort(a + 1, a + n + 1, cmp);
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%d\n", l);
  }
  return 0;
}
