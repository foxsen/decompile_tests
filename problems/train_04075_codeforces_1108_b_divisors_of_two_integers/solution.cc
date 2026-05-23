#include <bits/stdc++.h>
using namespace std;
int n, a[10009], x, mx, ans;
int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
    mx = max(x, mx);
  }
  for (int i = 1; i <= 10000; i++) {
    if (mx % i == 0) a[i]--;
    if (a[i] == 1) ans = i;
  }
  cout << mx << " " << ans << endl;
}
