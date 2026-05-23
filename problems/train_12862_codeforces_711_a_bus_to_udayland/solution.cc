#include <bits/stdc++.h>
int main() {
  int n, i = 0, flag = 0;
  char data[1010][10], crap;
  scanf("%d", &n);
  scanf("%c", &crap);
  while (i++ < n) {
    gets(data[i]);
  }
  i = 0;
  while (i++ < n) {
    if (data[i][1] == 'O' && data[i][0] == 'O') {
      flag = 1;
      data[i][1] = data[i][0] = '+';
      break;
    }
    if (data[i][3] == 'O' && data[i][4] == 'O') {
      flag = 1;
      data[i][3] = data[i][4] = '+';
      break;
    }
  }
  if (flag) {
    printf("YES\n");
    i = 0;
    while (i++ < n) {
      puts(data[i]);
    }
  } else
    printf("NO");
  return 0;
}
