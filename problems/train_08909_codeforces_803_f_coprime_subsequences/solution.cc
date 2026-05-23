#include <bits/stdc++.h>
using namespace std;
const int mx = 100005;
bool flag[mx], sqr[mx];
vector<long long> divs[mx];
long long prmdivs[mx], ara[mx];
void sieve() {
  long long i, j, k;
  for (i = 2; i < mx; i++) {
    if (sqr[i]) continue;
    if (!flag[i]) {
      for (j = i; j < mx; j += i) {
        prmdivs[j]++;
        divs[j].push_back(i);
        if (i != j) flag[j] = true;
      }
      for (j = i * i; j < mx; j += i * i) sqr[j] = true;
    } else
      for (j = i; j < mx; j += i) divs[j].push_back(i);
  }
}
long long bigmod(long long x, long long n) {
  long long ans = 1;
  while (n != 0) {
    if (n % 2 == 1) ans = (ans * x) % 1000000007;
    n /= 2;
    x = (x * x) % 1000000007;
  }
  return ans;
}
int main() {
  long long i, j, ans, n, m, x, temp, maxi;
  sieve();
  maxi = -1;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &x);
    maxi = max(maxi, x);
    m = divs[x].size();
    for (j = 0; j < m; j++) ara[divs[x][j]]++;
  }
  ans = bigmod(2, n) - 1;
  if (n != 1)
    for (i = 2; i <= maxi; i++) {
      if (ara[i] != 0) {
        temp = bigmod(2, ara[i]) - 1;
        if (prmdivs[i] % 2 == 0)
          ans += temp;
        else
          ans -= temp;
        ans = (ans % 1000000007 + 1000000007) % 1000000007;
      }
    }
  else {
    if (flag[x])
      ans = 0;
    else
      ans = 1;
  }
  printf("%lld\n", ans);
  return 0;
}
