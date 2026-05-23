#include <bits/stdc++.h>
using namespace std;
char s[100010];
bool b[100010], co[26];
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  co['a' - 'a'] = co['e' - 'a'] = co['i' - 'a'] = co['o' - 'a'] =
      co['u' - 'a'] = true;
  for (int i = 2; i <= len - 1; i++)
    if (!co[s[i] - 'a'] && !co[s[i - 1] - 'a'] && !co[s[i + 1] - 'a'] &&
        !b[i - 1])
      if (s[i - 1] != s[i] || s[i - 1] != s[i + 1] || s[i] != s[i + 1])
        b[i] = true;
  for (int i = 1; i <= len; i++) {
    printf("%c", s[i]);
    if (b[i]) printf(" ");
  }
  printf("\n");
  return 0;
}
