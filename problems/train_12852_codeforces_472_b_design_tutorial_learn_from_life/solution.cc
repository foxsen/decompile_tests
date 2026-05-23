#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int xx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int yy[] = {2, 2, 1, -1, -2, -2, -1, 1};
int main() {
  int arr[2010], meem, n, k, i;
  while (scanf("%d %d", &n, &k) == 2) {
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    meem = 0;
    for (i = n - 1; i >= 0; i -= k) meem += 2 * (arr[i] - 1);
    printf("%d\n", meem);
  }
  return 0;
}
