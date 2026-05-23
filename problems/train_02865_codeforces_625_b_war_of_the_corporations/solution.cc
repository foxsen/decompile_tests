#include <bits/stdc++.h>
using namespace std;
char a[100050];
char b[100];
int judge(int la, int lb) {
  int s = 0;
  for (int i = 0; i < lb; i++) {
    if (a[la] == b[i]) {
      s++;
      la++;
    } else {
      break;
    }
  }
  if (s == lb) {
    return 1;
  } else
    return 0;
}
int main() {
  while (~scanf("%s%s", a, b)) {
    int la = strlen(a);
    int lb = strlen(b);
    int sum = 0;
    for (int i = 0; i < la; i++) {
      if (a[i] == b[0]) {
        int result = judge(i, lb);
        if (result == 1) {
          sum++;
          i = i + lb - 1;
        }
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
