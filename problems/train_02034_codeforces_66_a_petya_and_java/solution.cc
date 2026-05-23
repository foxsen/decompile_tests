#include <bits/stdc++.h>
char range[10][40] = {
    "-128",
    "127",
    "-32768",
    "32767",
    "-2147483648",
    "2147483647",
    "-9223372036854775808",
    "9223372036854775807",
};
char a[105];
int in(char a[]) {
  int i = 1;
  if (a[0] == '-') i--;
  int x = strlen(a);
  for (; i < 8; i += 2) {
    int flag = 0;
    if (x < strlen(range[i])) return i;
    if (x > strlen(range[i])) continue;
    if (x == strlen(range[i])) {
      int j;
      for (j = 0; a[j] != '\0'; j++) {
        if (a[j] > range[i][j]) {
          flag = 1;
          break;
        }
        if (a[j] < range[i][j]) {
          flag = 0;
          break;
        }
      }
      if (flag == 0) return i;
    }
  }
  return 9;
}
int main() {
  while (scanf("%s", a) != EOF) {
    int x = in(a);
    x /= 2;
    if (x == 0) printf("byte\n");
    if (x == 1) printf("short\n");
    if (x == 2) printf("int\n");
    if (x == 3) printf("long\n");
    if (x == 4) printf("BigInteger\n");
  }
}
