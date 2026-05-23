#include <bits/stdc++.h>
using namespace std;
long long n;
char s[5010];
long long dpf[5][5010], dpnf[5][5010];
int main() {
  int i, j;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin.get();
    cin.get(s[i]);
  }
  int act = 1;
  dpf[act][0] = 0;
  dpnf[act][0] = 1;
  for (i = 1; i <= n; ++i) {
    dpf[act][i] = 1 + dpf[act][i - 1];
    dpnf[act][i] = i + 1 + dpnf[act][i - 1];
  }
  for (i = n - 1; i >= 1; --i) {
    act = 1 ^ act;
    if (s[i] == 'f') {
      dpf[act][0] = 0;
      dpnf[act][0] = dpf[1 ^ act][1];
      for (j = 1; j <= i; ++j) {
        dpf[act][j] = ((dpf[1 ^ act][j + 1] - dpf[1 ^ act][j]) % 1000000007 +
                       dpf[act][j - 1]) %
                      1000000007;
        if (dpf[act][j] < 0) dpf[act][j] += 1000000007;
        dpnf[act][j] = (dpf[1 ^ act][j + 1] + dpnf[act][j - 1]) % 1000000007;
      }
    } else {
      dpf[act][0] = 0;
      dpnf[act][0] = dpnf[1 ^ act][0];
      for (j = 1; j <= i; ++j) {
        dpf[act][j] = ((dpnf[1 ^ act][j] - dpnf[1 ^ act][j - 1]) % 1000000007 +
                       dpf[act][j - 1]) %
                      1000000007;
        if (dpf[act][j] < 0) dpf[act][j] += 1000000007;
        dpnf[act][j] = (dpnf[1 ^ act][j] + dpnf[act][j - 1]) % 1000000007;
      }
    }
  }
  cout << dpnf[act][0];
  return 0;
}
