#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      int k = i ^ j;
      if (k <= n && k >= 1 && k >= j && i + j > k) ans++;
    }
  printf("%d", ans);
}
