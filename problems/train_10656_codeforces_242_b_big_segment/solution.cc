#include <bits/stdc++.h>
using namespace std;
int n, l[100005], r[100005];
int main() {
  scanf("%d", &n);
  int x = 1 << 30, y = -1 << 30;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    x = min(x, l[i]);
    y = max(y, r[i]);
  }
  int ind = -1;
  for (int i = 0; i < n; i++) {
    if (l[i] <= x && y <= r[i]) ind = i + 1;
  }
  printf("%d\n", ind);
  return 0;
}
