#include <bits/stdc++.h>
using namespace std;
const long long pred = 1 << 21;
long long n, kek, s, d[pred][2], ans;
int main() {
  cin >> n;
  d[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    cin >> kek;
    s ^= kek;
    ++d[s][~i & 1];
  }
  for (int i = 0; i < pred; ++i) {
    ans += (d[i][0] * (d[i][0] - 1) + d[i][1] * (d[i][1] - 1)) >> 1;
  }
  cout << ans;
  return 0;
}
