#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r;
  cin >> n >> m >> r;
  int i = 0, x, min, max;
  while (i++ < n) {
    cin >> x;
    if (i == 1)
      min = x;
    else if (min > x)
      min = x;
  }
  i = 0;
  while (i++ < m) {
    cin >> x;
    if (i == 1)
      max = x;
    else if (max < x)
      max = x;
  }
  if (max <= min) {
    cout << r << endl;
    return 0;
  }
  cout << (max - min) * (r / min) + r << endl;
  return 0;
}
