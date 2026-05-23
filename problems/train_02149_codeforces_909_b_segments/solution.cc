#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans;
  scanf("%d", &n);
  if (n % 2 == 0)
    ans = (floor(n / 2) + 1) * ceil(n / 2);
  else
    ans = (floor(n / 2) + 1) * (n / 2 + 1);
  printf("%d\n", ans);
  return 0;
}
