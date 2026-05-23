#include <bits/stdc++.h>
using namespace std;
char ss[5][5];
int num1, num2;
int check() {
  int win1 = 0, win2 = 0;
  if (ss[1][1] == ss[1][2] && ss[1][2] == ss[1][3]) {
    if (ss[1][1] == 'X')
      win1++;
    else if (ss[1][1] == '0')
      win2++;
  }
  if (ss[2][1] == ss[2][2] && ss[2][2] == ss[2][3]) {
    if (ss[2][1] == 'X')
      win1++;
    else if (ss[2][1] == '0')
      win2++;
  }
  if (ss[3][1] == ss[3][2] && ss[3][2] == ss[3][3]) {
    if (ss[3][1] == 'X')
      win1++;
    else if (ss[3][1] == '0')
      win2++;
  }
  if (ss[1][1] == ss[2][1] && ss[2][1] == ss[3][1]) {
    if (ss[1][1] == 'X')
      win1++;
    else if (ss[1][1] == '0')
      win2++;
  }
  if (ss[1][2] == ss[2][2] && ss[2][2] == ss[3][2]) {
    if (ss[1][2] == 'X')
      win1++;
    else if (ss[1][2] == '0')
      win2++;
  }
  if (ss[1][3] == ss[2][3] && ss[2][3] == ss[3][3]) {
    if (ss[1][3] == 'X')
      win1++;
    else if (ss[1][3] == '0')
      win2++;
  }
  if (ss[1][1] == ss[2][2] && ss[2][2] == ss[3][3]) {
    if (ss[1][1] == 'X')
      win1++;
    else if (ss[1][1] == '0')
      win2++;
  }
  if (ss[1][3] == ss[2][2] && ss[2][2] == ss[3][1]) {
    if (ss[1][3] == 'X')
      win1++;
    else if (ss[1][3] == '0')
      win2++;
  }
  if (win1 == 0 && win2 == 0) return 0;
  if (win1 > 0 && win2 > 0) return -1;
  if (num1 - num2 == 0 && win1 > 0) return -1;
  if (num1 - num2 == 1 && win2 > 0) return -1;
  if (win1 > 0) return 1;
  if (win2 > 0) return 2;
}
void fl() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
int main() {
  char c;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      scanf("%c", &ss[i][j]);
      if (ss[i][j] == 'X')
        num1++;
      else if (ss[i][j] == '0')
        num2++;
    }
    if (i != 3) scanf("%c", &c);
  }
  if (!(num1 - num2 == 0 || num1 - num2 == 1)) {
    puts("illegal");
    return 0;
  }
  int flag = check();
  if (flag == -1)
    puts("illegal");
  else if (flag == 1)
    puts("the first player won");
  else if (flag == 2)
    puts("the second player won");
  else if (flag == 0) {
    if (num1 + num2 == 9)
      puts("draw");
    else if (num1 - num2 == 0)
      puts("first");
    else if (num1 - num2 == 1)
      puts("second");
  }
  return 0;
}
