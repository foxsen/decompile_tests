#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k + 1; i++) {
    if (i & 1)
      cout << i / 2 + 1 << " ";
    else
      cout << k + 2 - i / 2 << " ";
  }
  for (int i = k + 2; i <= n; i++) {
    cout << i << " ";
  }
  return 0;
}
