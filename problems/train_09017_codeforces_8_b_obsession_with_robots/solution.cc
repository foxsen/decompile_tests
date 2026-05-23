#include <bits/stdc++.h>
using namespace std;
const int dx[5] = {0, -1, 0, 1, 0};
const int dy[5] = {-1, 0, 1, 0, 0};
char S[111];
bool bio[400][400];
int main(void) {
  scanf("%s", S);
  int x = 200, y = 200;
  for (char *c = S; *c; ++c) {
    bio[x][y] = true;
    int xx = x, yy = y;
    if (*c == 'L') --x;
    if (*c == 'R') ++x;
    if (*c == 'U') ++y;
    if (*c == 'D') --y;
    for (int i = 0; i < 5; ++i) {
      int a = x + dx[i], b = y + dy[i];
      if (a == xx && b == yy) continue;
      if (bio[a][b]) {
        puts("BUG");
        return 0;
      }
    }
  }
  puts("OK");
  return 0;
}
