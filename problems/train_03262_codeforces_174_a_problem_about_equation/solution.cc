#include <bits/stdc++.h>
using namespace std;
double a[100];
int main() {
  int n;
  double b, sum, m = 0, one;
  cin >> n >> b;
  sum = b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    m = max(m, a[i]);
  }
  one = sum / n;
  if (m > one) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; i++) printf("%0.9lf\n", -a[i] + one);
}
