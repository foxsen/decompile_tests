#include <bits/stdc++.h>
using namespace std;
int n, k, m, a, b;
int flag, x;
int main() {
  flag = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    if (x % 2 == 1)
      a++;
    else
      b++;
  }
  if (k % 2 == 1) {
    if (n % 2 == 1) {
      m = n - (n - k) / 2;
      if (n == k && a % 2 == 1) flag = 1;
      if (a >= m) flag = 1;
    } else {
      m = (n - k + 1) / 2;
      if (a >= m) flag = 1;
    }
  } else {
    if (n % 2 == 1) {
      m = (n - k + 1) / 2;
      x = (n - k + 1) / 2;
      x = n - x;
      if (x >= a && a >= m) flag = 1;
    } else {
      if (n == k && a % 2 == 1) flag = 1;
    }
  }
  if (flag)
    printf("Stannis\n");
  else
    printf("Daenerys\n");
  return 0;
}
