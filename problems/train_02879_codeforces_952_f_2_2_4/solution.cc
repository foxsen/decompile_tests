#include <bits/stdc++.h>
using namespace std;
char c[1010];
int n, as, nw;
int main() {
  int i, j;
  scanf("%d%s", &as, c);
  n = strlen(c);
  for (i = 0; i < n;) {
    nw = c[i] - '0';
    j = i + 1;
    while (isdigit(c[j])) nw = nw * 10 + c[j] - '0', ++j;
    if (c[i] == '+')
      as += nw;
    else
      as -= nw;
    i = j;
  }
  cout << as;
  return 0;
}
