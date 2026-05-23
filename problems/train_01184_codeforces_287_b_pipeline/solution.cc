#include <bits/stdc++.h>
using namespace std;
long long n, tmp = 1;
int main() {
  int k, x = 0;
  cin >> n >> k;
  while (k != x && tmp < n) {
    x++;
    tmp += k - x;
  }
  if (tmp >= n) {
    cout << x << endl;
  } else {
    cout << -1 << endl;
  }
}
