#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, nh, oh = 0;
  cin >> h >> nh;
  oh += h;
  int m = 1;
  for (int i = 1; i <= m; i++) {
    if (h / nh > 0) {
      if (h % nh == 0) {
        oh += h / nh;
        h = h / nh;
        m++;
      } else {
        oh += h / nh;
        h = h / nh + h % nh;
        m++;
      }
    } else {
      cout << oh;
    }
  }
}
