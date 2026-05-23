#include <bits/stdc++.h>
using namespace std;
int n, cnt, x;
long long f[1000010], ans = 1;
signed main() {
  cin >> n;
  for (register int i = (1); i <= (n); ++i)
    scanf("%d", &x), cnt += (x == 1) ? 1 : 0;
  f[0] = f[1] = 1;
  for (register int i = (2); i <= (cnt); ++i)
    f[i] = (f[i - 2] * (i - 1) + f[i - 1]) % 1000000007;
  for (register int i = (n); i >= (cnt + 1); --i) ans = ans * i % 1000000007;
  cout << ans * f[cnt] % 1000000007 << endl;
  ;
  return 0;
}
