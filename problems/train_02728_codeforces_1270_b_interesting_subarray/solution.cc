#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n], ans = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i) {
      if (abs(a[i] - a[i + 1]) > 1) {
        puts("YES");
        printf("%d %d\n", i + 1, i + 2);
        ans = 1;
        break;
      }
    }
    if (!ans) puts("NO");
  }
}
