#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 5;
const long long md = 1e9 + 7;
const long long inf = 1e18;
int main() {
  long long i, j, w = 0, r = 0, x, l, k, q, n, m, R, zz = 0, v, z;
  cin >> q;
  while (q--) {
    long long a, b, c;
    cin >> a >> b >> c;
    i = 0;
    if (a > b) swap(a, b);
    while (a <= c && b <= c) {
      a += b;
      swap(a, b);
      i++;
    }
    cout << i << '\n';
  }
}
namespace {
auto fast_io = [] {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
}
