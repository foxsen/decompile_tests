#include <bits/stdc++.h>
using namespace std;
char str[5][5];
int main() {
  while (~scanf("%s", str[0])) {
    for (int i = 1; i < 4; i++) {
      scanf("%s", str[i]);
    }
    int a = 0;
    int b = 0;
    int flag = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        a = 0;
        b = 0;
        if (str[i][j] == '#')
          a++;
        else
          b++;
        if (str[i][j + 1] == '#')
          a++;
        else
          b++;
        if (str[i + 1][j] == '#')
          a++;
        else
          b++;
        if (str[i + 1][j + 1] == '#')
          a++;
        else
          b++;
        if (a >= 3 || b >= 3) flag = 1;
      }
    }
    if (flag) {
      printf("YES\n");
    }
    if (!flag) {
      printf("NO\n");
    }
  }
  return 0;
}
