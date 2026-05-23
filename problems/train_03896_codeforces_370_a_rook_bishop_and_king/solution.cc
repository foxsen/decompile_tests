#include <bits/stdc++.h>
using namespace std;
int main() {
  int c1, r1, c2, r2, R, P, K;
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
  if (r1 == r2 && c1 == c2)
    R = 0;
  else if (r1 == r2 || c1 == c2)
    R = 1;
  else
    R = 2;
  K = max(abs(c2 - c1), abs(r2 - r1));
  if ((r1 + c1) % 2 == (r2 + c2) % 2) {
    if (abs(c2 - c1) == abs(r2 - r1))
      P = 1;
    else
      P = 2;
  } else
    P = 0;
  printf("%d %d %d", R, P, K);
}
