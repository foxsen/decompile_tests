#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i = i / 2) {
    for (int j = 1; j <= n; j += i) {
      if (is_sorted(a + j, a + j + i)) {
        cout << i;
        return 0;
      }
    }
  }
}
