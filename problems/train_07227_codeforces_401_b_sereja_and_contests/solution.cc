#include <bits/stdc++.h>
using namespace std;
int arr[4005] = {0};
int main() {
  int x, k, count = 0, i, nmax, type, div1, div2;
  scanf("%d %d", &x, &k);
  arr[x] = 2;
  count++;
  while (k--) {
    scanf("%d", &type);
    if (type == 2) {
      scanf("%d", &div2);
      arr[div2] = 2;
      count++;
    } else {
      scanf("%d %d", &div2, &div1);
      arr[div2] = 2;
      count++;
      arr[div1] = 1;
      count++;
    }
  }
  nmax = x - count;
  count = 0;
  for (i = 1; i <= x; i++) {
    if (arr[i] == 0 && arr[i + 1] == 0) {
      i++;
      count++;
    } else if (arr[i] == 0)
      count++;
  }
  printf("%d %d\n", count, nmax);
  return 0;
}
