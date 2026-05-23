#include <bits/stdc++.h>
using namespace std;
double form1(double l) { return (sqrt(1 + 24 * l) - 1) / 6; }
int form2(int h) { return h * (3 * h + 1) / 2; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int count = 0;
    while (n != 0) {
      double l = n;
      int h = form1(l);
      if (h == 0) break;
      count += n / form2(h);
      n = n % form2(h);
    }
    cout << count << '\n';
  }
}
