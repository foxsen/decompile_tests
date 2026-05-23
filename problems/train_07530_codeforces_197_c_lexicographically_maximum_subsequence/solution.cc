#include <bits/stdc++.h>
int main() {
  char str[100005];
  int pos = 0;
  scanf("%s", str);
  for (int i = 25; i >= 0; i--) {
    for (int j = pos; str[j]; j++) {
      if (str[j] == i + 'a') {
        printf("%c", str[j]);
        pos = j;
      }
    }
  }
}
