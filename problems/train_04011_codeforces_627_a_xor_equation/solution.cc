#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
} _;
int main() {
  long long s, x;
  cin >> s >> x;
  auto diff = (s - x);
  if (diff % 2 || diff < 0 || (x << 1) & diff) {
    cout << 0;
  } else {
    long long count = 1;
    for (int i = 63; i >= 0; --i)
      if ((x >> i) & 1) count <<= 1;
    cout << count - 2 * (diff == 0);
  }
}
