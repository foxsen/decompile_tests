#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, x;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (v[0] != v[n - 1])
    cout << n - 1;
  else {
    int temp1, temp2;
    for (int i = 1; i < n - 1; i++)
      if (v[i] != v[0]) {
        temp1 = max(i, n - i - 1);
        break;
      }
    for (int i = n - 2; i >= 1; i--) {
      if (v[i] != v[0]) {
        temp2 = max(i, n - i - 1);
        break;
      }
    }
    cout << max(temp1, temp2);
  }
}
