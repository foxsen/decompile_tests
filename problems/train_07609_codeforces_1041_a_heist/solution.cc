#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int n, x, m = 1000000000000000, t = -1, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (x < m) m = x;
    if (x > t) t = x;
  }
  cout << (t - m + 1) - n;
}
