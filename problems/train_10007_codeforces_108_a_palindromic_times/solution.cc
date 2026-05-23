#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, k;
  char s[7], c[7], d[7];
  scanf("%s", s);
  c[0] = s[0];
  c[1] = s[1];
  c[2] = '\0';
  d[0] = s[4];
  d[1] = s[3];
  d[2] = '\0';
  int b = 0;
  for (i = 1; i >= 0; i--) {
    b = b * 10 + c[i];
  }
  int f = 0;
  for (i = 3; i <= 4; i++) {
    f = f * 10 + s[i];
  }
  if (strcmp(c, d) == 0) {
    if (c[0] == '0' || c[0] == '1') {
      if (c[1] < '5') {
        c[1] = c[1] + 1;
        printf("%s:%c%c", c, c[1], c[0]);
      } else if (c[1] == '5') {
        c[0] = c[0] + 1;
        c[1] = '0';
        printf("%s:%c%c", c, c[1], c[0]);
      }
    } else if (c[0] == '2') {
      if (c[1] <= '2') {
        c[1] = c[1] + 1;
        printf("%s:%c%c", c, c[1], c[0]);
      } else
        printf("00:00");
    }
  } else {
    if (c[0] == '0' || c[0] == '1') {
      if ((b > f) && (c[1] <= '5')) {
        printf("%s:%c%c", c, c[1], c[0]);
      } else if ((f > b) && (c[1] <= '4')) {
        c[1] = c[1] + 1;
        printf("%s:%c%c", c, c[1], c[0]);
      } else {
        c[0] = c[0] + 1;
        c[1] = '0';
        printf("%s:%c%c", c, c[1], c[0]);
      }
    } else if (c[0] == '2') {
      if ((b > f) && (c[1] <= '3')) {
        printf("%s:%c%c", c, c[1], c[0]);
      } else if (f > b) {
        if (c[1] <= '2') {
          c[1] = c[1] + 1;
          printf("%s:%c%c", c, c[1], c[0]);
        } else
          printf("00:00");
      }
    }
  }
  return 0;
}
