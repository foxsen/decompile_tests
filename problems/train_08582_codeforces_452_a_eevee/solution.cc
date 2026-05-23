#include <bits/stdc++.h>
char s[16];
char poke[16][16] = {"vaporeon", "jolteon", "flareon", "espeon",
                     "umbreon",  "leafeon", "glaceon", "sylveon"};
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < 8; i++)
    if ((int)strlen(poke[i]) == n) {
      int j;
      for (j = 0; j < n; j++)
        if (s[j] != '.' and s[j] != poke[i][j]) {
          break;
        }
      if (j == n) {
        printf("%s\n", poke[i]);
        return 0;
      }
    }
}
