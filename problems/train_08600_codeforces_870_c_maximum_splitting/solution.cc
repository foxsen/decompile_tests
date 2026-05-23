#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, ans = 0;
    cin >> n;
    if (n % 2) {
      n -= 9;
      ans++;
    }
    if (n < 4 & n != 0)
      ans = -1;
    else
      ans += (n / 4);
    cout << ans << "\n";
  }
  return 0;
}
