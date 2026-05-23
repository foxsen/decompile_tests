#include <bits/stdc++.h>
using namespace std;
int n, a[20] = {0};
int main() {
  int n, ma = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    ma = max(ma, x);
    a[i] = x;
  }
  printf("%d\n", ma ^ a[n]);
  return 0;
}
