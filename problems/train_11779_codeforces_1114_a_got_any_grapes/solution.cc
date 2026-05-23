#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  scanf("%d%d%d", &a, &b, &c);
  if (x > a) {
    printf("NO");
    return 0;
  }
  a = a - x;
  if (y > a + b) {
    printf("NO");
    return 0;
  }
  if (z > a + b + c - y) {
    printf("NO");
    return 0;
  }
  printf("YES");
  return 0;
}
