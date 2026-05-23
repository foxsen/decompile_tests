#include <bits/stdc++.h>
using namespace std;
int gcd(int first_number, int second_number) {
  int gcd;
  for (int i = 1; i <= first_number && i <= second_number; i++) {
    if (first_number % i == 0 && second_number % i == 0) {
      gcd = i;
    }
  }
  return gcd;
}
int main() {
  int a, b, n, i = 0;
  cin >> a >> b >> n;
  while (n != 0) {
    if (i % 2 == 0) {
      int r = gcd(a, n);
      n = n - r;
      i++;
    } else {
      int r = gcd(b, n);
      n = n - r;
      i++;
    }
  }
  if (i % 2 == 1) {
    cout << "0";
  } else {
    cout << "1";
  }
  return 0;
}
