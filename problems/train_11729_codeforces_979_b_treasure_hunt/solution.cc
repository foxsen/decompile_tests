#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mz = 1e9 + 7;
char s[N];
int p[5][255];
int main() {
  int n;
  cin >> n;
  int len[5];
  for (int i = 1; i <= 3; i++) {
    scanf("%s", s);
    len[i] = strlen(s);
    for (int j = 0; j < len[i]; j++) {
      p[i][s[j]]++;
      if (p[i][s[j]] > p[i][0]) p[i][0] = p[i][s[j]];
    }
  }
  int a = p[1][0];
  if (a == len[1] && n == 1)
    a = len[1] - 1;
  else
    a = min(a + n, len[1]);
  int b = p[2][0];
  if (b == len[2] && n == 1)
    b = len[2] - 1;
  else
    b = min(b + n, len[2]);
  int c = p[3][0];
  if (c == len[3] && n == 1)
    c = len[3] - 1;
  else
    c = min(c + n, len[3]);
  if (a == b && a > c || b == c && b > a || a == c && a > b ||
      a == b && b == c) {
    puts("Draw");
  } else if (a > b && a > c) {
    puts("Kuro");
  } else if (b > c) {
    puts("Shiro");
  } else {
    puts("Katie");
  }
  return 0;
}
