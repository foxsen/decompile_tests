#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long r, g, b;
    cin >> r >> g >> b;
    long long mx = max(max(r, g), b);
    long long sum = r + g + b;
    if (mx > (sum + 1) / 2) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
