#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = 0; i < 31; i++) {
      if (((a >> i) & 1) && ((b >> i) & 1)) res |= (1 << i);
    }
    cout << (res ^ a) + (res ^ b) << "\n";
  }
  return 0;
}
