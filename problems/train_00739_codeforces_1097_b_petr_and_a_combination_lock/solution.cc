#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < 1 << n; ++i) {
    int res = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1)
        res = (res + a[j]) % 360;
      else
        res = (res - a[j] + 360) % 360;
    }
    if (res == 0) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
