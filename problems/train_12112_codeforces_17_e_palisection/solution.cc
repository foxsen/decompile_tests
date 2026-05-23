#include <bits/stdc++.h>
using namespace std;
const int mx = 4e6 + 5;
const int mod = 51123987;
char str[mx], s[mx];
int p[mx];
int l[mx], r[mx];
long long pow_mod(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
void manacher(char str[], char s[], int n) {
  s[0] = '$';
  s[1] = '#';
  for (int i = 1; i <= n; i++) s[i * 2] = str[i - 1], s[i * 2 + 1] = '#';
  s[2 * n + 2] = '\0';
  n = 2 * n + 1;
  int mxx = 0, id = 0;
  for (int i = 1; i <= n; i++) {
    p[i] = mxx > i ? min(p[2 * id - i], mxx - i) : 1;
    while (s[i + p[i]] == s[i - p[i]]) p[i]++;
    if (mxx < i + p[i]) {
      mxx = i + p[i];
      id = i;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  manacher(str, s, n);
  int len = 2 * n + 1;
  long long ans = 0;
  for (int i = 1; i <= len; i++) {
    l[i - p[i] + 1]++;
    l[i + 1]--;
    r[i]++;
    r[i + p[i]]--;
    ans = (ans + p[i] / 2) % mod;
  }
  ans = ans * (ans - 1) % (2 * mod) / 2 % mod;
  long long tmp = 0;
  for (int i = 1; i <= len; i++) {
    l[i] += l[i - 1];
    r[i] += r[i - 1];
    if (i % 2 == 0) {
      ans -= tmp * l[i] % mod;
      ans = (ans % mod + mod) % mod;
      tmp = (tmp + r[i]) % mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
