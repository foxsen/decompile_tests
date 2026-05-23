#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, S, q, ans = 0;
  cin >> T >> S >> q;
  while (T > S) {
    ans++;
    S *= q;
  }
  cout << ans;
}
