#include <bits/stdc++.h>
using namespace std;
char s[100005], ans[100005];
int main() {
  int n;
  scanf("%d", &n);
  int flag = 0, flag2 = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    if (s[0] == '0')
      flag = 1;
    else {
      if (s[0] != '1') {
        flag2 = 1;
        strcpy(ans, s);
      } else {
        int flag1 = 0;
        for (int j = 1; j < strlen(s); j++) {
          if (s[j] != '0') {
            flag1 = 1;
            break;
          }
        }
        if (flag1 == 1) {
          flag2 = 1;
          strcpy(ans, s);
        } else
          cnt += strlen(s) - 1;
      }
    }
  }
  if (flag == 1)
    printf("0\n");
  else {
    if (flag2 == 1)
      printf("%s", ans);
    else
      printf("1");
    for (int i = 0; i < cnt; i++) printf("0");
    printf("\n");
  }
  return 0;
}
