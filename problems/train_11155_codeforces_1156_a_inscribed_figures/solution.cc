#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    if ((a[i] == 3 && a[i - 1] == 2) || (a[i] == 2 && a[i - 1] == 3) ||
        (a[i] == a[i - 1])) {
      cout << "Infinite";
      return 0;
    }
  }
  cout << "Finite\n";
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) continue;
    if (a[i] == 1 && a[i - 1] == 2) {
      cnt += 3;
    } else if (a[i] == 1 && a[i - 1] == 3) {
      cnt += 4;
    } else if (a[i] == 2 && a[i - 1] == 1) {
      cnt += 3;
    } else if (a[i] == 3 && a[i - 1] == 1) {
      cnt += 4;
    }
  }
  for (int i = 0; i + 2 < n; i++) {
    if (a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2) cnt--;
  }
  cout << cnt;
  return 0;
}
