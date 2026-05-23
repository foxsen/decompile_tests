#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n % 2 != 0) {
      n -= 3;
      printf("7");
    }
    n /= 2;
    while (n--) {
      printf("1");
    }
    printf("\n");
  }
  return 0;
}
