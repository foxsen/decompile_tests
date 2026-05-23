#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    int count = 0;
    int ans;
    cin >> n;
    for (int i = 1; i <= 1666; i++) {
      if ((i % 10 != 3) && i % 3 != 0) {
        count++;
      }
      if (count == n) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
