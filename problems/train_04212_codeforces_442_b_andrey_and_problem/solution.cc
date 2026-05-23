#include <bits/stdc++.h>
using namespace std;
double fun(double a, double b) { return (a * (1 - b)) + ((1 - a) * b); }
double Max(double a, double b, double c) { return fmax(fmax(a, b), c); }
double cmp(double a, double b) { return a > b; }
int main() {
  ios::sync_with_stdio(false);
  int n;
  double a[1000], max;
  while (cin >> n) {
    max = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n, cmp);
    double temp = a[0], temp2 = (1.0 - a[0]);
    max = a[0];
    for (int i = 1; i < n; i++) {
      temp = temp * (1.0 - a[i]) + a[i] * temp2;
      max = Max(max, temp, a[i]);
      temp2 *= (1.0 - a[i]);
    }
    cout << fixed << setprecision(12) << max << endl;
  }
  return 0;
}
