#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool ch(long long a) {
  long long ans = 0, res = 1;
  while (a >= res) {
    ans += a / res;
    res *= k;
  }
  return ans >= n;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  long long l = 1, r = n;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (ch(mid))
      r = mid;
    else
      l = mid;
  }
  if (ch(l))
    cout << l;
  else
    cout << l + 1;
  return 0;
}
