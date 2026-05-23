#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int main() {
  int x = 0, k = 1;
  for (int i = 1;; i++) {
    x = x + i;
    a[k++] = x;
    if (a[k - 1] > 100000) break;
  }
  int n;
  scanf("%d", &n);
  if (n == 0) {
    puts("a");
    return 0;
  }
  x = 0;
  while (n != 0) {
    int p = lower_bound(a + 1, a + k, n) - a;
    if (a[p] != n) {
      p--;
    }
    n -= a[p];
    char ch = x + 'a';
    for (int i = 1; i <= p + 1; i++) printf("%c", ch);
    x++;
  }
  printf("\n");
  return 0;
}
