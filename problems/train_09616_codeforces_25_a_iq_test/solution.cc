#include <bits/stdc++.h>
using namespace std;
int a[105], jq;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 3; i++) {
    cin >> a[i];
  }
  jq = (a[1] % 2 + a[2] % 2 + a[3] % 2) / 2;
  for (int i = 1; i <= n; i++) {
    if (i > 3) cin >> a[i];
    if (a[i] % 2 != jq) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
