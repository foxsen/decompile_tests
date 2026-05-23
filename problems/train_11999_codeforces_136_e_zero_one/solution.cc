#include <bits/stdc++.h>
using namespace std;
const int MaxN = int(2e5);
const long double pi = 3.1415926535897932384626433832795;
char s[MaxN];
int main() {
  while (gets(s)) {
    int len = strlen(s);
    int tmp = (len - 2) / 2 + len % 2;
    int one = 0, two = 0;
    for (int i = (0); i <= (len - 1); i++) {
      one += s[i] == '1';
      two += s[i] == '?';
    }
    if (one <= tmp) puts("00");
    if (one + two >= tmp + 1 && one < tmp + 2) {
      if (s[len - 1] == '1' || (s[len - 1] == '?' && one < tmp + 1)) puts("01");
      if (s[len - 1] == '0' || (s[len - 1] == '?' && one + two - 1 > tmp))
        puts("10");
    }
    if (one + two >= tmp + 2) puts("11");
    puts("");
  }
  return 0;
}
