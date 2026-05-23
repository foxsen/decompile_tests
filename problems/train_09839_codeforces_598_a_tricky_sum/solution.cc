#include <bits/stdc++.h>
using namespace std;
int main() {
  int te;
  cin >> te;
  while (te--) {
    long long n;
    cin >> n;
    long long t = 1;
    while (t <= n) {
      t *= 2;
    }
    long long ans = 0;
    long long ans1 = (1 + n) * n / 2;
    t /= 2;
    long long ans2;
    ans2 = t * 2 - 1;
    ans = ans1 - 2 * ans2;
    cout << ans << endl;
  }
}
