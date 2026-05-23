#include <bits/stdc++.h>
using namespace std;
const long MaxN = 1000;
long n, ans;
long a[MaxN];
long t[MaxN][MaxN];
int main() {
  cin >> n;
  for (long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  t[1][0] = 1;
  if (a[1] == 1) {
    t[1][2] = 1;
  } else if (a[1] == 2) {
    t[1][1] = 1;
  }
  if (a[1] == 0) {
    t[1][1] = 1;
    t[1][2] = 1;
  }
  for (long i = 2; i <= n; i++) {
    t[i][0] = min(min(t[i - 1][1], t[i - 1][2]), t[i - 1][0]) + 1;
    if (a[i] == 0) {
      t[i][1] = t[i][0];
      t[i][2] = t[i][0];
    }
    if (a[i] == 1) {
      t[i][1] = t[i - 1][2];
      t[i][2] = t[i][0];
    }
    if (a[i] == 2) {
      t[i][1] = t[i][0];
      t[i][2] = t[i - 1][1];
    }
    if (a[i] == 3) {
      t[i][1] = t[i - 1][2];
      t[i][2] = t[i - 1][1];
    }
  }
  if (a[n] == 3) {
    ans = min(min(t[n][1], t[n][2]), t[n][0]);
  } else {
    ans = t[n][a[n]];
  }
  cout << ans;
  return 0;
}
