#include <bits/stdc++.h>
using namespace std;
const int PRIME = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int aCount = 0;
    for (int i = 0; i < n; i++) {
      aCount += a[i] == '1';
    }
    int bCount = 0;
    for (int i = 0; i < n; i++) {
      bCount += b[i] == '1';
    }
    if (aCount == 0) {
      if (bCount == 0) {
        cout << 0 << '\n';
      } else {
        cout << -1 << '\n';
      }
      continue;
    }
    int ans = INT32_MAX;
    if (aCount == bCount) {
      int numSimilar = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] == '1' && b[i] == '0') {
          numSimilar++;
        }
      }
      ans = numSimilar * 2;
    }
    if (n - (aCount - 1) == bCount) {
      int goodInv = 0;
      int numOneOver = 0;
      int numZeroOver = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
          if (b[i] == '0') {
            goodInv++;
          } else {
            numOneOver++;
          }
        } else {
          if (b[i] == '1') {
            goodInv++;
          } else {
            numZeroOver++;
          }
        }
      }
      ans = min(ans, (numOneOver - 1) * 2 + 1);
    }
    if (ans == INT32_MAX) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
}
