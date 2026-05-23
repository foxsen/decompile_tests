#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int i;
    i = (y - x) / (a + b);
    if ((y - x) % (a + b) == 0) {
      cout << i << endl;
    } else {
      cout << "-1" << endl;
    }
    --t;
  }
  return 0;
}
