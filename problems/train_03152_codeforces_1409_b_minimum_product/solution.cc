#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    ll a1 = a, b1 = b, x1 = x, y1 = y, n1 = n;
    ll temp = min(n, a - x);
    a -= temp;
    n -= temp;
    temp = min(n, b - y);
    b -= temp;
    n -= temp;
    temp = min(n1, b1 - y1);
    b1 -= temp;
    n1 -= temp;
    temp = min(n1, a1 - x1);
    a1 -= temp;
    n1 -= temp;
    cout << min(a * b, a1 * b1) << '\n';
  }
}
