#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int const N = 100 * 1000 + 16;
int const M = 1000 * 1000 * 1000 + 7;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    int mx = 0;
    if (x & 1) mx++, x -= 9;
    if (x == 0)
      mx = 1;
    else if (x < 4)
      mx = -1;
    else
      mx += x / 4;
    cout << mx << "\n";
  }
}
