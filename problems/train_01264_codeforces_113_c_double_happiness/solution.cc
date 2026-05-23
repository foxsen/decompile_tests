#include <bits/stdc++.h>
using namespace std;
bitset<300000001> prime;
int main() {
  int l, r;
  cin >> l >> r;
  int res = l <= 2 && r >= 2;
  prime.set();
  prime[0] = false;
  prime[1] = false;
  for (int i = 3; i * i <= r; i += 2)
    if (prime[i]) {
      for (int j = i * i; j <= r; j += (i << 1)) prime[j] = false;
    }
  int f = l / 4 * 4 + 1;
  if (f < l) f += 4;
  for (int i = f; i <= r; i += 4) res += prime[i];
  printf("%d\n", res);
  return 0;
}
