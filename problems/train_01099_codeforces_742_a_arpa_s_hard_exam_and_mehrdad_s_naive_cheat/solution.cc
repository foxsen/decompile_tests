#include <bits/stdc++.h>
using namespace std;
int n;
int ksm(int x) {
  int tt = 1378, rtn = 1;
  while (x) {
    if (x & 1) rtn = (rtn * tt) % 10;
    x >>= 1;
    tt = (tt * tt) % 10;
  }
  return rtn;
}
int main() {
  scanf("%d", &n);
  printf("%d\n", ksm(n) % 10);
  return 0;
}
