#include <bits/stdc++.h>
using namespace std;
long long k[100007], cnt[100007];
int n;
int main() {
  long long res, cur, now;
  int i;
  scanf("%d", &n);
  res = 0;
  for (i = 0; i < n; ++i) {
    scanf("%I64d%I64d", &k[i], &cnt[i]);
    now = k[i];
    cur = 1;
    while (cur < cnt[i]) {
      ++now;
      cur *= 4;
    }
    if (now == k[i]) {
      ++now;
    }
    res = max(res, now);
  }
  printf("%I64d\n", res);
  return 0;
}
