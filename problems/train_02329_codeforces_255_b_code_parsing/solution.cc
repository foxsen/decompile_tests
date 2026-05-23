#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int len, cntx, cnty;
int main() {
  int i;
  scanf("%s", s);
  len = strlen(s);
  for (i = 0, cntx = 0, cnty = 0; i < len; i++)
    if (s[i] == 'x')
      cntx++;
    else
      cnty++;
  if (cntx > cnty) {
    for (i = 0; i < cntx - cnty; i++) printf("x");
    printf("\n");
  } else {
    for (i = 0; i < cnty - cntx; i++) printf("y");
    printf("\n");
  }
  return 0;
}
