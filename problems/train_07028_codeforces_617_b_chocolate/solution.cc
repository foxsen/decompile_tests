#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int cnt = 1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int x = 0;
    while (a[x] != 1) {
      x++;
    }
    long long int ans = 0;
    for (int i = x; i < n; i++) {
      if (a[i] == 1) {
        if (ans == 0) ans = 1;
        ans = ans * cnt;
        cnt = 1;
      } else {
        cnt++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
