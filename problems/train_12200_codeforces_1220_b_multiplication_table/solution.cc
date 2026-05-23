#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int a, b, c, d, t, i, br[1000], j;
  cin >> t;
  for (i = 0; i < t * t; i++) {
    {
      if (i < t)
        cin >> br[i];
      else
        cin >> c;
    }
    if (i == t + 2) a = sqrt((br[2] * br[1]) / c);
  }
  cout << a << " ";
  for (i = 1; i < t; i++) {
    cout << br[i] / a;
    if (i < t - 1) cout << " ";
  }
}
