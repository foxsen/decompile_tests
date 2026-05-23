#include <bits/stdc++.h>
using namespace std;
const int N = 1200;
char s[N];
int main(void) {
  int n;
  while (~scanf("%d", &n)) {
    scanf("%s", s);
    int one = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') one++;
    }
    bool flag = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == '1' && s[i - 1] == s[i]) {
        flag = 0;
        break;
      }
    }
    for (int i = 2; i < n; i++) {
      if (s[i - 1] == '0' && s[i - 2] == '0' && s[i] == '0') {
        flag = 0;
        break;
      }
    }
    if (n > 2) {
      if (s[0] == '0' && s[1] == '0') flag = 0;
      if (s[n - 1] == '0' && s[n - 2] == '0') flag = 0;
    }
    if (n == 1 && one == 0) flag = 0;
    if (n == 2 && one != 1) flag = 0;
    puts(flag ? "Yes" : "No");
  }
  return 0;
}
