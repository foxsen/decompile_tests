#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long x, ans = 0, remaining = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    long long cur = min(remaining, x / 2);
    ans += cur;
    x -= 2 * cur;
    remaining -= cur;
    ans += x / 3;
    x %= 3;
    remaining += x;
  }
  cout << ans << '\n';
}
