#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int mx = max(a, max(b, c));
    int h = a + b + c - 3 * mx;
    h = abs(h);
    n -= h;
    if (n % 3 == 0 && n >= 0) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
}
