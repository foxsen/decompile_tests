#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 1e6 + 6, OO = 0x3f3f3f3f;
string x = "AOYEUI";
char s[105];
int main() {
  scanf("%s", s);
  int sz = strlen(s);
  for (int i = 0; i < sz; ++i) {
    if (x.find(toupper(s[i])) != -1) continue;
    printf(".%c", tolower(s[i]));
  }
  return 0;
}
