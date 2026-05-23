#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t a, b, n, q;
  cin >> q;
  while (q--) {
    cin >> a >> b >> n;
    n %= 3;
    int pd[3];
    pd[0] = a;
    pd[1] = b;
    pd[2] = pd[0] ^ pd[1];
    cout << pd[n] << endl;
  }
  return 0;
}
