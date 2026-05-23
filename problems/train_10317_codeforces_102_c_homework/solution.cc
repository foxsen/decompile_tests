#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[101000];
  scanf("%s", s);
  int n = strlen(s), k;
  bool exist[101000];
  scanf("%d", &k);
  int br[250];
  memset(br, 0, sizeof(br));
  memset(exist, 0, sizeof(exist));
  for (int i = 0; i < n; i++) {
    br[(int)s[i]]++;
  }
  while (1) {
    int minn = 9999999, tmp;
    for (int i = (int)'a'; i <= (int)'z'; i++)
      if (br[i] != 0 && br[i] < minn) minn = br[i], tmp = i;
    if (k < minn || minn == 9999999) break;
    br[tmp] = 0;
    k -= minn;
    exist[tmp] = 1;
  }
  int ans = 0;
  for (int i = 0; i < 250; i++)
    if (br[i] > 0) ans++;
  char c[101000];
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (exist[(int)s[i]] == 0) {
      c[cnt++] = s[i];
    }
  printf("%d\n", ans);
  printf("%s\n", c);
  return 0;
}
