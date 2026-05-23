#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, T, m;
  double c;
  cin >> n >> T >> c;
  vector<int> a;
  a.resize(n);
  double mean1 = 0.0;
  double mean2 = 0.0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  int p;
  cin >> p;
  for (int i = 0; i < n; i++) {
    mean1 += a[i];
    mean2 = (mean2 + double(a[i]) / double(T)) / c;
    if (i >= T) {
      mean1 -= a[i - T];
    }
    if (i + 1 == p) {
      double real = mean1 / T;
      printf("%.6f %.6f %.6f", real, mean2, abs(mean2 - real) / real);
      cout << endl;
      if (--m) {
        cin >> p;
      } else
        break;
    }
  }
  return 0;
}
