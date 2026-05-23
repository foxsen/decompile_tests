#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
char str[maxn];
int num[27];
int main() {
  scanf("%s", str);
  int len = strlen(str);
  if (len < 26) {
    printf("-1\n");
    return 0;
  }
  bool is_ok = false;
  int point = 0;
  for (int i = 0; i < len; i++) {
    for (int k = 0; k < 26; k++) num[k] = -1;
    int j = 0;
    for (; j < 26 && i + j < len; j++) {
      if (str[i + j] != '?' && num[str[i + j] - 'A'] != -1) {
        i = num[str[i + j] - 'A'];
        break;
      }
      if (str[i + j] >= 'A' && str[i + j] <= 'Z') num[str[i + j] - 'A'] = i + j;
    }
    if (j == 26) {
      point = i;
      is_ok = true;
      break;
    }
  }
  if (is_ok == false)
    printf("-1\n");
  else {
    for (int i = 0; i < point; i++) {
      if (str[i] == '?')
        printf("A");
      else
        printf("%c", str[i]);
    }
    for (int i = point; i < point + 26; i++) {
      if (str[i] == '?') {
        for (int j = 0; j < 26; j++) {
          if (num[j] == -1) {
            printf("%c", j + 'A');
            num[j] = 0;
            break;
          }
        }
      } else
        printf("%c", str[i]);
    }
    for (int i = point + 26; i < len; i++) {
      if (str[i] == '?')
        printf("A");
      else
        printf("%c", str[i]);
    }
    printf("\n");
  }
  return 0;
}
