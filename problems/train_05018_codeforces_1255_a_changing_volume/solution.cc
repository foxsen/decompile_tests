#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    int a, b;
    cin >> a >> b;
    int c = abs(a - b);
    int ans = 0;
    int d = c / 5;
    c -= d * 5;
    int e = c / 2;
    c -= e * 2;
    ans = ans + d + e + c;
    cout << ans << endl;
  }
}
