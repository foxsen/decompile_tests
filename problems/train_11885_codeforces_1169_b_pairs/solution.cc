#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int n, m, a, b, x, y, sum, sum1, sum2, sum3, a1[N], a2[N];
int main() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  sum1 = sum = 1;
  for (int i = 1; i < m; i++) {
    scanf("%d%d", &a, &b);
    if (a == x || b == x)
      sum++;
    else
      sum2 = max(sum2, max(++a1[a], ++a1[b]));
    if (a == y || b == y)
      sum1++;
    else
      sum3 = max(sum3, max(++a2[a], ++a2[b]));
  }
  if (sum + sum2 == m || sum1 + sum3 == m)
    puts("YES");
  else
    puts("NO");
  return 0;
}
