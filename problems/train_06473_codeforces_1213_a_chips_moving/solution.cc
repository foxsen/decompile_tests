#include <bits/stdc++.h>
int ODD;
int EVEN;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x & 1)
      ODD++;
    else
      EVEN++;
  }
  printf("%d", (ODD < EVEN) ? ODD : EVEN);
  return 0;
}
