#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, flag = 1, figure;
  char c1[101], c2[101], k, c[201];
  scanf("%d", &n);
  scanf("%s", c);
  for (i = 0; i < n; i++) {
    c1[i] = c[i];
    c2[i] = c[i + n];
  }
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      if (c1[i] > c1[j]) {
        k = c1[i];
        c1[i] = c1[j];
        c1[j] = k;
      }
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      if (c2[i] > c2[j]) {
        k = c2[i];
        c2[i] = c2[j];
        c2[j] = k;
      }
  if (c1[0] < c2[0]) figure = 0;
  if (c1[0] > c2[0]) figure = 1;
  if (c1[0] == c2[0]) {
    printf("NO\n");
    figure = 2;
    flag = 0;
  }
  for (i = 1; i < n; i++) {
    if (figure == 1 && c1[i] <= c2[i]) {
      printf("NO\n");
      flag = 0;
      break;
    }
    if (figure == 0 && c1[i] >= c2[i]) {
      printf("NO\n");
      flag = 0;
      break;
    }
  }
  if (flag) printf("YES\n");
  return 0;
}
