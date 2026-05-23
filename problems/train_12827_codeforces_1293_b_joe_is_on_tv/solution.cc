#include <bits/stdc++.h>
using namespace std;
int main() {
  long double n;
  cin >> n;
  long double sum = 0;
  ios_base::sync_with_stdio(0);
  while (n > 0) {
    long double x;
    x = 1 / n;
    sum = sum + x;
    n--;
  }
  cout << fixed << setprecision(12) << sum;
}
