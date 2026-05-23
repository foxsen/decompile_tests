#include <bits/stdc++.h>
int main(void) {
  int i, l;
  char a[200];
  scanf("%s", a);
  for (i = 0; a[i] != '\0'; i++)
    ;
  l = i;
  for (i = 0; i < l; i++) {
    if (a[i] == '.') {
      printf("0");
    }
    if (a[i] == '-') {
      if (a[i + 1] == '.') {
        printf("1");
        i = i + 1;
      } else if (a[i + 1] == '-') {
        printf("2");
        i = i + 1;
      }
    }
  }
  return 0;
}
