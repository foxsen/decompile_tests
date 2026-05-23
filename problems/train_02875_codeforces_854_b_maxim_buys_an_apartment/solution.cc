#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, minimum = 1, maximum;
  cin >> n >> k;
  if (k == n) {
    minimum = 0;
  }
  if (k == 0) {
    maximum = 0;
    minimum = 0;
  } else if (n / k >= 3) {
    maximum = 2 * k;
  } else {
    int p = n / 3;
    maximum = 3 * p;
    k = k - n % 3;
    maximum = maximum - k;
  }
  cout << minimum << " " << maximum;
  return 0;
}
