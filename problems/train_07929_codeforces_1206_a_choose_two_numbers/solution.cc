#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, i, j, t, k, lie, m, n, o, x, y, z, ar[111], br[111];
  scanf("%lld", &a);
  for (i = 0; i < a; i++) scanf("%lld", &ar[i]);
  scanf("%lld", &b);
  for (i = 0; i < b; i++) scanf("%lld", &br[i]);
  sort(ar, ar + a);
  sort(br, br + b);
  cout << ar[a - 1] << ' ' << br[b - 1] << "\n";
  return 0;
}
