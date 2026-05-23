#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int a, b, x;
  cin >> a >> b;
  x = min(a, b);
  unsigned long int fact = 1;
  while (x > 1) {
    fact = fact * x;
    x--;
  }
  cout << fact;
  return (0);
}
