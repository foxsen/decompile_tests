#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long l, r;
  cin >> l >> r;
  long long ret = 0, in = 1ll << 62;
  while ((l & in) == (r & in) && in) {
    in >>= 1;
  }
  cout << max(0ll, (in << 1) - 1);
  return 0;
}
