#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, t;
  cin >> n >> m;
  while (m--) {
    cin >> t;
    while (t % 2 == 0) {
      t = t / 2 + n;
    }
    cout << (t + 1) / 2 << endl;
  }
  return 0;
}
