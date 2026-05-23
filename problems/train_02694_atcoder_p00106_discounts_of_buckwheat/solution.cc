#include <stdio.h>

int main() {
  int stack[50], sp = 0, n, i, sum;
  while (scanf("%d", &stack[sp++]) != EOF)
    ;
  for (i = 0; i < sp; i++) {
    int ans = 1000000;
    n = stack[i];
    if (n == 0)
      break;
    for (int a = 0; a <= 50; a++) {
      for (int b = 0; b <= 50; b++) {
        for (int c = 0; c <= 50; c++) {
          sum = (380 * (5 * (a / 5))) * 0.8 + (a % 5) * 380;
          sum += (550 * (4 * (b / 4))) * 0.85 + (b % 4) * 550;
          sum += (850 * (3 * (c / 3))) * 0.88 + (c % 3) * 850;
          if (a * 200 + b * 300 + c * 500 == n) {
            if (sum < ans)
              ans = sum;
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}