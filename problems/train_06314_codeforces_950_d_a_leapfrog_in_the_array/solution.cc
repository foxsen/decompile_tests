#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main() {
  long long int n, q;
  cin >> n >> q;
  while (q--) {
    long long int x;
    cin >> x;
    long long int ans;
    int flag = 1;
    for (int i = 64; i >= 1; i--) {
      long long int temp = pow(2, i);
      long long int r1 = (x - 2 * n + temp) % temp;
      if (r1 == 0) {
        long long int ans = (x - 2 * n) / temp;
        ans += 2 * n + 1;
        ans /= 2;
        cout << ans << endl;
        flag = 0;
        break;
      }
    }
    if (flag) cout << (x + 1) / 2 << endl;
    ;
  }
  return 0;
}
