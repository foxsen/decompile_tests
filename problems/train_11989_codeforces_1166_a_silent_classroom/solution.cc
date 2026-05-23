#include <bits/stdc++.h>
using namespace std;
long long n, m, k, t, caseno;
char s[200005];
long long cnt[200005];
int main() {
  long long i, j;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", &s);
    cnt[s[0]]++;
  }
  long long res = 0;
  for (i = 'a'; i <= 'z'; i++) {
    long long mot = cnt[i];
    long long d1 = mot / 2;
    long long d2 = mot - d1;
    res += (d1 * (d1 - 1)) / 2;
    res += (d2 * (d2 - 1)) / 2;
  }
  printf("%lld\n", res);
  return 0;
}
