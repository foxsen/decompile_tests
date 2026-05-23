#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r, x;
  int sum;
  cin >> sum;
  for (int i = 1; i <= sum; ++i) {
    cin >> l >> r;
    x = l * 2;
    if (x <= r)
      cout << l << " " << x << endl;
    else
      cout << "-1 -1\n";
  }
  return 0;
}
