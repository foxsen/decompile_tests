#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    int n, i, j, k;
    cin >> n;
    if (n & 1) {
      cout << "YES\n";
      int a[2 * n], ct = 1, chance = 0;
      for (i = 0; i < n; i++) {
        if (chance & 1) {
          a[i] = ct + 1;
          a[i + n] = ct;
        } else {
          a[i] = ct;
          a[i + n] = ct + 1;
        }
        ct += 2;
        chance++;
      }
      for (i = 0; i < 2 * n; i++) cout << a[i] << " ";
      cout << "\n";
    } else {
      cout << "NO";
    }
  }
  return 0;
}
