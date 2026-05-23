#include <bits/stdc++.h>
using namespace std;
unsigned long long c = 0;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0)
    return a;
  else if (a > b) {
    c = c + (a / b);
    return gcd(b, a % b);
  } else {
    c = c + (b / a);
    return gcd(a, b % a);
  }
}
int main() {
  unsigned long long a, b;
  cin >> a >> b;
  gcd(a, b);
  cout << c << "\n";
  return 0;
}
