#include <bits/stdc++.h>
using namespace std;
int arr[1000000], val[1000000], mark[1000000];
int freq[1000000];
void sieve() {
  int i, j;
  for (i = 2; i * i <= 500000; ++i) {
    if (arr[i] == 0) {
      for (j = i + i; j <= 500000; j += i) {
        if (!arr[j]) arr[j] = i;
      }
    }
  }
  for (i = 2; i <= 500000; ++i) {
    if (!arr[i]) arr[i] = i;
  }
}
int main() {
  sieve();
  int tmp, n, q, i, j, k, a, b, c, x, y, z, lim, tot;
  long long int ans;
  scanf("%d", &n);
  scanf("%d", &q);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &val[i]);
  }
  ans = 0ll;
  tot = 0;
  int c1 = 0;
  while (q--) {
    scanf("%d", &x);
    a = val[x];
    vector<int> v;
    while (a != 1) {
      k = arr[a];
      v.push_back(k);
      while (a % k == 0) a /= k;
    }
    lim = (1 << v.size());
    tmp = 0;
    for (i = 1; i < lim; ++i) {
      if (__builtin_popcount(i) & 1) {
        a = 1;
      } else {
        a = -1;
      }
      y = 1;
      for (j = 0; j < v.size(); ++j) {
        if (i & (1 << j)) y *= v[j];
      }
      tmp += (a * freq[y]);
    }
    if (mark[x] == 0) {
      mark[x] = 1;
      ans += (tot - tmp);
      tot++;
      for (i = 1; i < lim; ++i) {
        y = 1;
        for (j = 0; j < v.size(); ++j) {
          if (i & (1 << j)) {
            y *= v[j];
          }
        }
        freq[y]++;
      }
    } else {
      mark[x] = 0;
      if (val[x] == 1)
        ans -= (tot - 1);
      else
        ans -= (tot - tmp);
      tot--;
      for (i = 1; i < lim; ++i) {
        y = 1;
        for (j = 0; j < v.size(); ++j) {
          if (i & (1 << j)) {
            y *= v[j];
          }
        }
        freq[y]--;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
