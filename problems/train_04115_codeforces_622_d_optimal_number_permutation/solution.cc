#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int main() {
  int i, j, fl, test, even, odd;
  scanf("%d", &n);
  odd = 1;
  even = 1;
  for (i = 1; i < n; i++) {
    if (i % 2) {
      a[odd] = i;
      a[n - odd + 1] = i;
      odd++;
    } else {
      a[even + n] = i;
      a[2 * n - even] = i;
      even++;
    }
  }
  for (i = 1; i <= 2 * n; i++) {
    if (a[i] == 0)
      printf("%d ", n);
    else
      printf("%d ", a[i]);
  }
  return 0;
}
