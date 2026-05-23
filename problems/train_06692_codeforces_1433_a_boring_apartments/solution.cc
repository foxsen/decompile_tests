#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, ans;
    cin >> x;
    vector<int> digits;
    while (x > 0) {
      digits.push_back(x % 10);
      x /= 10;
    }
    ans = (digits[0] - 1) * 10;
    int n = digits.size();
    ans += n * (n + 1) / 2;
    cout << ans << endl;
  }
  return 0;
}
