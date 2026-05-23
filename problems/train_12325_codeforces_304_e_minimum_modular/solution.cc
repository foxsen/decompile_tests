#include <bits/stdc++.h>
using namespace std;
int num[5010], cnt[1000010];
int vi[1000010];
int main() {
  int n, k, kk, mlen;
  while (scanf("%d%d", &n, &k) == 2) {
    kk = k * (k + 1) / 2;
    mlen = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &num[i]);
    sort(num, num + n);
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        ++cnt[num[j] - num[i]], mlen = max(mlen, num[j] - num[i]);
    for (int i = 1; i < 1000010; ++i) {
      int sum = 0;
      for (int j = i; j <= mlen && sum <= kk; j += i) sum += cnt[j];
      if (sum > kk) continue;
      sum = 0;
      for (int j = 0; j < n && sum <= k; ++j) {
        if (vi[num[j] % i] == i) ++sum;
        vi[num[j] % i] = i;
      }
      if (sum <= k) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}
