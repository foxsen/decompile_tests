#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int f = 0;
    cin >> a[0];
    for (int i = 1; i < n; i++) {
      cin >> a[i];
      if (a[i] >= a[i - 1]) {
        f = 1;
      }
    }
    if (f == 1) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
