#include <bits/stdc++.h>
using namespace std;
int bs(int a, int l1, int r1, int n, int m) {
  int l = l1, r = r1;
  int mid;
  while (r - l > 1) {
    mid = l + (r - l) / 2;
    if (mid / 2 + mid / 3 - mid / 6 >= a && mid / 2 >= n && mid / 3 >= m) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (l / 2 + l / 3 - l / 6 >= a && l / 2 >= n && l / 3 >= m) {
    return l;
  } else {
    return r;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int ans = bs(n + m, 0, 1000000000, n, m);
  cout << ans << endl;
  return 0;
}
