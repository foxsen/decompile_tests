#include <bits/stdc++.h>
using namespace std;
void f() {
  int n;
  cin >> n;
  int a[n];
  int l = -1, r = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1 && l == -1) l = i;
    if (a[i] == 1) r = i;
  }
  int count = 0;
  int ans = 0;
  for (int i = l; i <= r; i++) {
    if (a[i] == 0)
      count++;
    else {
      ans += count;
      count = 0;
    }
  }
  ans += count;
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    f();
  }
}
