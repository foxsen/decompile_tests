#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = 1001001001;
long long n, a, b, c, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> a >> b >> c;
  if (n < min(a, b)) {
    cout << 0;
    return 0;
  }
  if (a > b - c && n - b >= 0) {
    ans = (n - b) / (b - c) + 1 + ((n - b) % (b - c) + c) / a;
  } else {
    ans = n / a;
  }
  cout << ans;
  return 0;
}
