#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int s[maxn];
int flag[maxn];
int main() {
  int n, i, j;
  scanf("%d", &n);
  int k = n * 2, ans = 0, e = 0, num = 0;
  for (i = 0; i < k; i++) {
    char c[10];
    scanf("%s", c);
    if (c[0] == 'a') {
      int x;
      scanf("%d", &x);
      s[e++] = x;
    } else if (c[0] == 'r') {
      if (s[e - 1] != num + 1 && !flag[e - 1]) {
        ans++;
        flag[e - 2] = 1;
      } else if (flag[e - 1]) {
        if (e - 2 >= 0) flag[e - 2] = 1;
        flag[e - 1] = 0;
      }
      e--;
      num++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
