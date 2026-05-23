#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
      while (a[i] > 0 && d >= i) {
        a[0]++;
        d = d - i;
        a[i]--;
      }
    }
    cout << a[0] << endl;
  }
}
