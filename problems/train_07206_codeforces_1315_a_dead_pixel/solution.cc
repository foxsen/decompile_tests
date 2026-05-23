#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    x++;
    y++;
    long long l1 = (x - 1) * b;
    long long l2 = (a - x) * b;
    long long l3 = (y - 1) * a;
    long long l4 = (b - y) * a;
    cout << max(l1, max(l2, max(l3, l4))) << "\n";
  }
}
