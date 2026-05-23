#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = 1e18;
int main() {
  double n, i, k, m = 101;
  cin >> n;
  vector<long long> a(n, 0);
  vector<double> b(101, 0);
  for (i = 0; i < (n); i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  double x = 0, y = 0;
  for (i = 0; i < (101); i++) {
    if (b[i] >= y) {
      b[i] -= y;
      y = 0;
    } else {
      y -= b[i];
      b[i] = 0;
    }
    if (b[i] >= x) {
      y += ((i + 1) * ceil((b[i] - x) / (i + 1))) - (b[i] - x);
      x += ceil((b[i] - x) / (i + 1));
    } else {
      y += (x - b[i]);
    }
  }
  cout << x;
  return 0;
}
