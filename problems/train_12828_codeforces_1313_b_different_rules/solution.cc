#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, x, y;
    cin >> n >> x >> y;
    long long int top1, bl1, top2, bl2, min = 0, max = 0;
    top1 = x - 1;
    bl1 = n - x;
    if (bl1 != 0 && bl1 >= (y - 1)) {
      if ((y - 1) <= 0)
        max += bl1;
      else
        max += bl1 - (y - 1);
    }
    if (top1 != 0 && (top1) >= (n - (y + 1))) {
      if ((n - (y + 1)) <= 0)
        min += top1;
      else
        min += top1 - (n - (y + 1));
    }
    if (y == n && x != n) min += 1;
    cout << (1 + min) << " " << (n - max) << endl;
  }
  return 0;
}
