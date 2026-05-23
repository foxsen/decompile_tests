#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int mx = min(n / k, m);
    int rst = m - mx;
    int p = ceil(rst / (double)(k - 1));
    cout << mx - p << '\n';
  }
}
