#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a1, a2, k1 = 0, k2 = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a1 >> a2;
    if (a1 > 0)
      k1++;
    else
      k2++;
  }
  if (k1 <= 1 || k2 <= 1)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
