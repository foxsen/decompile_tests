#include <bits/stdc++.h>
int main() {
  int n, i, number, count_out, counter;
  scanf("%d", &n);
  char s[n];
  int flag = 0, max = 0, waiter = 0, cautious = 0;
  number = count_out = 0;
  for (i = 0; i < n; i++) {
    scanf(" %c", &s[i]);
    if (s[i] == '(') {
      flag = 1;
      counter = 0;
      waiter = 1;
      max = (count_out > max) ? count_out : max;
      count_out = 0;
    } else if (s[i] == ')') {
      if (counter > 0) number++;
      flag = 0;
    } else if (s[i] == '_') {
      if (flag) {
        if (counter > 0) {
          number++;
        }
        counter = 0;
      } else {
        max = (count_out > max) ? count_out : max;
        count_out = 0;
      }
    } else if (flag) {
      counter++;
    } else if (flag == 0)
      count_out++, max = (count_out > max) ? count_out : max;
  }
  printf("%d %d", max, number);
  return 0;
}
