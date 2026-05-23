#include <bits/stdc++.h>
using namespace std;
long long cal(long long n, long long k) {
  long long ret = 1;
  while (n--) ret *= k--;
  return ret;
}
char s[100001];
bool vit[10];
int main() {
  long long n, i, q = 0, num = 0, ret;
  scanf("%s", s);
  n = strlen(s);
  for (i = 0; i < n; i++) {
    q += s[i] == '?';
    if ('A' <= s[i] && s[i] <= 'J') vit[s[i] - 'A'] = true;
  }
  for (i = 0; i < 10; i++) num += vit[i];
  if (s[0] == '?') {
    ret = 9 * cal(num, 10);
    q--;
  } else if ('A' <= s[0] && s[0] <= 'J') {
    ret = 9 * cal(num - 1, 9);
  } else {
    ret = cal(num, 10);
  }
  for (i = 0; i < q; i++) s[i] = '0';
  s[q] = '\0';
  printf("%lld%s", ret, s);
  return 0;
}
