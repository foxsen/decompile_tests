#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int M = 1e9 + 7;
const int N = 2e5 + 5;
int main() {
  long long n;
  cin >> n;
  long long ans = 1 + n * (6 + 3 * (n - 1));
  cout << ans << endl;
  return 0;
}
