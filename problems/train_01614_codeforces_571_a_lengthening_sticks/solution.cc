#include <bits/stdc++.h>
using namespace std;
int find(int a, int b, int c, int d) {
  int l = b + c - a + d;
  if (l >= 0) {
    if (l % 2 == 0)
      return l / 2 - 1;
    else
      return l / 2;
  } else
    return -1;
}
long long int binop(int A) {
  if (A >= 2)
    return (long long int)((long long int)A * (A - 1)) / 2;
  else
    return 0LL;
}
int main() {
  int a, b, c, l, x, y, z, i;
  long long int ans, ans1;
  ans = 0LL;
  scanf("%d%d%d%d", &a, &b, &c, &l);
  for (i = 0; i <= l; i++) {
    x = find(a, b, c, i);
    y = find(b, a, c, i);
    z = find(c, a, b, i);
    if (x >= 0 && y >= 0 && z >= 0) {
      ans1 = binop(i + 2) - binop(i - x + 1) - binop(i - y + 1) -
             binop(i - z + 1) + binop(i - x - y) + binop(i - y - z) +
             binop(i - x - z);
      ans += ans1;
    }
  }
  cout << ans << endl;
  return 0;
}
