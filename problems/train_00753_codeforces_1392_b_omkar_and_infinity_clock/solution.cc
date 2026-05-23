#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, i, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long a[n], maxa;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (k % 2 != 0) {
      maxa = a[0];
      for (i = 0; i < n; i++) {
        maxa = max(maxa, a[i]);
      }
      for (i = 0; i < n; i++) {
        a[i] = maxa - a[i];
      }
    } else {
      maxa = a[0];
      for (i = 0; i < n; i++) {
        maxa = max(maxa, a[i]);
      }
      for (i = 0; i < n; i++) {
        a[i] = maxa - a[i];
      }
      maxa = a[0];
      for (i = 0; i < n; i++) {
        maxa = max(maxa, a[i]);
      }
      for (i = 0; i < n; i++) {
        a[i] = maxa - a[i];
      }
    }
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
