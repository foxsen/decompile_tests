#include <bits/stdc++.h>
using namespace std;
int n, io, oi;
char sq[1010], tmp[1010];
int main() {
  scanf("%d", &n);
  scanf("%s", sq);
  io = oi = 0;
  for (int i = 0; i < n; i++) {
    if (sq[i] - '0' == i % 2) {
      io++;
    } else
      oi++;
  }
  printf("%d\n", oi > io ? io : oi);
  return 0;
}
