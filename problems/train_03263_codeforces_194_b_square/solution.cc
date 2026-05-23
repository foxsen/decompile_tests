#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long int n;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    if (n % 2 == 0)
      cout << 4 * n + 1;
    else if (n % 4 == 1)
      cout << 2 * n + 1;
    else if (n % 4 == 3)
      cout << n + 1;
    else
      ;
    cout << "\n";
  }
  return 0;
}
