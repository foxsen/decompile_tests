#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, i, j, k;
  scanf("%lld", &n);
  ;
  scanf("%lld", &m);
  ;
  long long int ans = 0;
  long long int temp = n - 1, len1 = 0, len2 = 0;
  while (temp != 0) {
    len1++;
    temp /= 7;
  }
  temp = m - 1;
  while (temp != 0) {
    len2++;
    temp /= 7;
  }
  if (len1 == 0) len1++;
  if (len2 == 0) len2++;
  if (len1 + len2 <= 7) {
    for (i = 0; i < (1 << 7); i++) {
      if (__builtin_popcount(i) != len1 + len2) continue;
      vector<long long int> vec;
      for (j = 0; j < 7; j++) {
        if (i & (1 << j)) vec.push_back(j);
      }
      do {
        long long int left = 0, right = 0, pow7 = 1;
        for (j = len1 - 1; j >= 0; j--) {
          left = left + pow7 * vec[j];
          pow7 *= 7;
        }
        pow7 = 1;
        for (j = len1 + len2 - 1; j >= len1; j--) {
          right = right + pow7 * vec[j];
          pow7 *= 7;
        }
        if (left < n and right < m) ans++;
      } while (next_permutation(vec.begin(), vec.end()));
    }
  }
  printf("%lld\n", ans);
  return 0;
}
