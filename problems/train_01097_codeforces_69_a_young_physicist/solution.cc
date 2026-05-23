#include <bits/stdc++.h>
int main() {
  int n, x, y, z;
  scanf("%d", &n);
  int arr[1][3];
  arr[0][0] = arr[0][1] = arr[0][2] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &x, &y, &z);
    arr[0][0] += x;
    arr[0][1] += y;
    arr[0][2] += z;
  }
  if (arr[0][0] == 0 && arr[0][1] == 0 && arr[0][2] == 0)
    printf("YES");
  else
    printf("NO");
  return 0;
}
