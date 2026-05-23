#include <bits/stdc++.h>
int value(int boy, int girl, int game) {
  int b;
  int r;
  int sum;
  b = 0;
  r = 0;
  sum = 0;
  while (b <= boy) {
    while (r <= girl) {
      if (b + r == game)
        sum++;
      else if (b + r > game)
        break;
      r++;
    }
    r = 0;
    b++;
  }
  return (sum);
}
int main(void) {
  int boy;
  int girl;
  int game;
  int otvet;
  boy = 0;
  girl = 0;
  game = 0;
  otvet = 0;
  scanf("%d\n%d\n%d", &boy, &girl, &game);
  otvet = value(boy, girl, game);
  printf("%d\n", otvet);
  return (0);
}
