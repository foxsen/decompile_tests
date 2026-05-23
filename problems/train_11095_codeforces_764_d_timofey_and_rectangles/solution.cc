#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    int arr[4];
    for (int j = 0; j < 4; j++) {
      scanf("%d", &arr[j]);
    }
    int x = arr[0] % 2;
    if (x < 0) x = 1;
    int y = arr[1] % 2;
    if (y < 0) y = 1;
    printf("%d\n", (2 * x) + (y) + 1);
  }
}
