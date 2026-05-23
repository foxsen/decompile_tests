#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n, flag;
    flag = 0;
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++) cin >> a[j];
    sort(a, a + n);
    for (int k = 1; k < n; k++) {
      if (a[k] - a[k - 1] == 1) {
        cout << 2 << endl;
        flag = 1;
        break;
      }
    }
    if (flag == 0) cout << 1 << endl;
  }
}
