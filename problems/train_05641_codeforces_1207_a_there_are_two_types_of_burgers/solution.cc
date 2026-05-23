#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int ans = 0;
    long long int b, p, f, h, c;
    cin >> b >> p >> f >> h >> c;
    if (h >= c) {
      long long int temp = min(b / 2, p);
      ans += temp * h;
      b -= temp * 2;
      temp = min(b / 2, f);
      ans += temp * c;
    } else {
      long long int temp = min(b / 2, f);
      ans += temp * c;
      b -= temp * 2;
      temp = min(b / 2, p);
      ans += temp * h;
    }
    cout << ans << "\n";
  }
  return 0;
}
