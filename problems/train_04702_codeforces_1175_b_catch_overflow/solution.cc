#include <bits/stdc++.h>
using namespace std;
int n, re;
long long ans;
long long stck[100010];
bool chstck[100010];
bool over;
int main() {
  scanf("%d", &n);
  stck[0] = 1;
  chstck[0] = true;
  for (int i = 1; i <= n; i++) {
    char in[10];
    scanf("%s", in);
    if (in[0] == 'a') {
      ans += stck[re];
      if (ans >= 4294967296 || !chstck[re]) {
        over = true;
      }
    }
    if (in[0] == 'f') {
      int num;
      scanf("%d", &num);
      stck[re + 1] = stck[re] * num;
      ++re;
      if (stck[re] < 4294967296 && chstck[re - 1])
        chstck[re] = true;
      else
        chstck[re] = false;
    }
    if (in[0] == 'e') {
      re--;
    }
  }
  if (over) {
    printf("OVERFLOW!!!");
    return 0;
  }
  printf("%lld", ans);
}
