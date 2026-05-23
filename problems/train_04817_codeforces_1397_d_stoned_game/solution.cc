#include <bits/stdc++.h>
using namespace std;
int T, n, a[105], sum;
int main() {
  scanf("%d", &T);
  while (T--) {
    sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n - 1; i++) sum += a[i];
    if (sum < a[n])
      puts("T");
    else {
      sum += a[n];
      if (sum & 1)
        puts("T");
      else
        puts("HL");
    }
  }
  return 0;
}
