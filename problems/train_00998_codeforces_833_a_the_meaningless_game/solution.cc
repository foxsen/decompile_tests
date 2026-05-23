#include <bits/stdc++.h>
using namespace std;
long long r;
bool is_perfect_cube(long long n) {
  r = (long long)round(cbrt(n));
  if (r * r * r == n) return true;
  return false;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (is_perfect_cube((long long)a * b)) {
      if (((long long)a + b) % r == 0)
        printf("Yes\n");
      else
        printf("No\n");
    } else
      printf("No\n");
  }
  return 0;
}
