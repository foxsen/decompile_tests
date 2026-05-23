#include <bits/stdc++.h>
using namespace std;
int n, i, R, x, c[333333];
void add(int x) {
  for (; x; x -= x & -x) c[x]++;
}
int qu(int x) {
  if (!x) return 0;
  int V = 0;
  for (; x <= n; x += x & -x) V += c[x];
  return V;
}
int main() {
  scanf("%d", &n);
  R = n;
  printf("1");
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    add(x);
    for (; qu(R) == n - R + 1 && R; R--)
      ;
    printf(" %d", i - (n - R) + 1);
  }
}
