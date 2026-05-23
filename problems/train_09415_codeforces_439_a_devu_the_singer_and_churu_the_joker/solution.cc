#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, s = 0, i;
  cin >> n >> d;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if ((n - 1) * 10 + s > d)
    cout << "-1";
  else
    cout << (d - s) / 5;
  return 0;
}
