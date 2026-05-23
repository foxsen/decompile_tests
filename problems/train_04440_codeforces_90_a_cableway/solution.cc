#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int x[3], i;
  for (i = 0; i < 3; ++i) scanf("%d", x + i);
  for (i = 0; x[0] || x[1] || x[2]; ++i)
    if (x[i % 3] >= 2)
      x[i % 3] -= 2;
    else
      x[i % 3] = 0;
  printf("%d\n", i + 29);
  return 0;
}
