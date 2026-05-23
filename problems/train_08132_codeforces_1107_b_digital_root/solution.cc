#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long int x, k;
    cin >> k >> x;
    cout << 9 * (k - 1) + x << endl;
  }
  return 0;
}
