#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (m % n != 0) {
    cout << "-1" << endl;
    return 0;
  }
  long long d = m / n;
  int ans = 0;
  while (d % 2 == 0) {
    d = d / 2;
    ans++;
  }
  while (d % 3 == 0) {
    d = d / 3;
    ans++;
  }
  if (d == 1) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
  }
}
