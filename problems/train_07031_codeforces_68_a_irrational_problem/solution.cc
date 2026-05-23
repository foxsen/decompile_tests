#include <bits/stdc++.h>
using namespace std;
int main() {
  int p[4], p0[4], a, b;
  cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
  sort(p, p + 4);
  int i;
  int ans = 0;
  for (i = a; i <= b; i++) {
    int s = 0;
    memcpy(p0, p, sizeof(p));
    do {
      if (i % p0[0] % p0[1] % p0[2] % p0[3] == i) s++;
    } while (next_permutation(p0, p0 + 4));
    if (s >= 7) ans++;
  }
  cout << ans << endl;
  return 0;
}
