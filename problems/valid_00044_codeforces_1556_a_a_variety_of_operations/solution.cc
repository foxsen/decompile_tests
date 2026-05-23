#include <bits/stdc++.h>
using namespace std;
void sol() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a == 0 && b == 0)
    printf("0\n");
  else if (a == b)
    printf("1\n");
  else if (abs(b - a) % 2 == 0)
    printf("2\n");
  else
    printf("-1\n");
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) sol();
}
