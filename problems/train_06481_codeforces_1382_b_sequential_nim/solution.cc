#include <bits/stdc++.h>
long long a[120000];
using namespace std;
int main() {
  int n, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    int ying = 2;
    if (n == 1)
      printf("First\n");
    else {
      for (int i = 0; i < n; i++) {
        ying = 3 - ying;
        if (a[i] > 1) {
          break;
        }
      }
      if (ying == 1)
        printf("First\n");
      else
        printf("Second\n");
    }
  }
  return 0;
}
