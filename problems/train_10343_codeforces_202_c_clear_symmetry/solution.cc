#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n;
  cin >> x;
  n = 1;
  int sum = 1;
  while (sum < x) {
    n += 2;
    sum = (n / 2 + 1) * (n / 2 + 1) + (n / 2) * (n / 2);
  }
  if (x == 3) n = 5;
  cout << n << endl;
  return 0;
}
