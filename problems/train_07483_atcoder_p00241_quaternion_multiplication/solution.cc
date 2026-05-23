#include<iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    while (n--) {
      int x1, y1, z1, w1, x2, y2, z2, w2;
      cin >> x1 >> y1 >> z1 >> w1 >> x2 >> y2 >> z2 >> w2;
      cout << x1 * x2 - y1 * y2 - z1 * z2 - w1 * w2 << " "
	   << x1 * y2 + y1 * x2 + z1 * w2 - w1 * z2 << " "
	   << x1 * z2 - y1 * w2 + z1 * x2 + w1 * y2 << " "
	   << x1 * w2 + y1 * z2 - z1 * y2 + w1 * x2 << endl;
    }
  }
  return 0;
}