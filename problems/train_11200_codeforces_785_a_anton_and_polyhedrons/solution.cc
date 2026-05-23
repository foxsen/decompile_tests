#include <bits/stdc++.h>
int main() {
  int n, i, sum = 0;
  char item[15];
  scanf("%d", &n);
  while (n) {
    scanf("%s", item);
    switch (item[0]) {
      case 'T':
        sum += 4;
        break;
      case 'C':
        sum += 6;
        break;
      case 'O':
        sum += 8;
        break;
      case 'D':
        sum += 12;
        break;
      case 'I':
        sum += 20;
        break;
    }
    n--;
  }
  printf("%d", sum);
}
