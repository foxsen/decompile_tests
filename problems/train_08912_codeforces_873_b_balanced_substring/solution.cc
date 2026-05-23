#include <bits/stdc++.h>
using namespace std;
char ch[1100000];
int a[1100000], n, i, sum, vis[1100000], ans;
int main() {
  sum = 200000;
  scanf("%d", &n);
  scanf("%s", ch);
  for (i = 1; i <= n; i++) {
    a[i] = ch[i - 1] - '0';
    a[i] = (a[i] == 0) ? -1 : 1;
  }
  for (i = 1; i <= 400000; i++) vis[i] = -1;
  vis[sum] = 0;
  for (i = 1; i <= n; i++) {
    sum = sum + a[i];
    if (vis[sum] == -1)
      vis[sum] = i;
    else
      ans = max(ans, i - vis[sum]);
  }
  printf("%d\n", ans);
}
