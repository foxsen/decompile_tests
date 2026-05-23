#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int i;
  for (i = 0; i < n; i++) {
    if (a[i] <= k) {
      sum++;
    } else {
      break;
    }
  }
  if (i == n) {
    printf("%d\n", sum);
    return 0;
  }
  for (i = n - 1; i >= 0; i--) {
    if (a[i] <= k) {
      sum++;
    } else {
      break;
    }
  }
  printf("%d\n", sum);
  return 0;
}
