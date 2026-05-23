#include <bits/stdc++.h>
int cmpfunc(const void *a, const void *b) { return (*(int *)a) - (*(int *)b); }
int main() {
  long long int a, b;
  int arr1[20], arr2[20], flag[20] = {0}, i = 0, n1, n2, j, final[20], t,
                          tatti = 0, ind[20], x = 0;
  scanf("%lld %lld", &a, &b);
  while (a > 0) {
    arr1[i] = a % 10;
    a = a / 10;
    i++;
  }
  n1 = i;
  i = 0;
  while (b > 0) {
    arr2[i] = b % 10;
    b = b / 10;
    i++;
  }
  n2 = i;
  i--;
  t = 0;
  qsort(arr1, n1, sizeof(int), cmpfunc);
  if (n1 < n2) {
    for (i = n1 - 1; i >= 0; i--) printf("%d", arr1[i]);
  } else {
    while (t < n1) {
      for (j = n1 - 1; j >= 0; j--) {
        if (flag[j] == 0 && arr1[j] <= arr2[i]) {
          if (arr1[j] < arr2[i]) tatti = 1;
          final[t] = arr1[j];
          flag[j] = 1;
          t++;
          i--;
          ind[x] = j;
          x++;
          break;
        }
      }
      while (j == -1) {
        i++;
        t--;
        x--;
        flag[ind[x]] = 0;
        for (j = n1 - 1; j >= 0; j--) {
          if (flag[j] == 0 && arr1[j] < arr2[i]) {
            tatti = 1;
            final[t] = arr1[j];
            flag[j] = 1;
            t++;
            i--;
            break;
          }
        }
      }
      if (tatti == 1) {
        for (j = n1 - 1; j >= 0; j--) {
          if (flag[j] == 0) {
            final[t] = arr1[j];
            t++;
          }
        }
      }
    }
    for (i = 0; i < n1; i++) printf("%d", final[i]);
  }
  return 0;
}
