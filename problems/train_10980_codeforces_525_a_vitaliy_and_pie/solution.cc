#include <bits/stdc++.h>
int main() {
  long int a[100] = {0}, b = 0, i, m, n;
  char c;
  scanf("%ld", &m);
  n = (2 * m) - 2;
  scanf("%c", &c);
  for (i = 0; i < n; i++) {
    scanf("%c", &c);
    if (i % 2 == 0)
      a[c - 32]++;
    else if (a[c] > 0)
      a[c]--;
    else
      b++;
  }
  printf("%ld\n", b);
  return 0;
}
