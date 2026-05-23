#include <bits/stdc++.h>
const int maxn = 100005;
using namespace std;
char c[maxn];
int main() {
  int n, x, y, x1, y1, i;
  while (scanf("%d", &n) != EOF) {
    int flag = 0;
    int sum = 0;
    scanf("%d%d%d%d", &x, &y, &x1, &y1);
    scanf("%s", c);
    for (i = 0; c[i] != '\0'; i++) {
      if (c[i] == 'E') {
        if (x < x1) x += 1;
      } else if (c[i] == 'S') {
        if (y > y1) y -= 1;
      } else if (c[i] == 'W') {
        if (x > x1) x -= 1;
      } else if (c[i] == 'N') {
        if (y < y1) y += 1;
      }
      sum++;
      if (x == x1 && y == y1) {
        flag = 1;
        break;
      }
    }
    if (flag)
      printf("%d\n", sum);
    else
      printf("-1\n");
  }
  return 0;
}
