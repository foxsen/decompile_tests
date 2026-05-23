#include <bits/stdc++.h>
using namespace std;
int t, n, dat[101010], l1, l2;
int main() {
  cin >> t;
  while (t > 0) {
    t--;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> dat[i];
    l1 = max(dat[0], dat[1]);
    l2 = min(dat[0], dat[1]);
    for (int i = 2; i < n; i++) {
      if (dat[i] >= l1) {
        l2 = l1;
        l1 = dat[i];
      } else if (dat[i] > l2) {
        l2 = dat[i];
      }
    }
    cout << min(l2 - 1, n - 2) << endl;
  }
  return 0;
}
