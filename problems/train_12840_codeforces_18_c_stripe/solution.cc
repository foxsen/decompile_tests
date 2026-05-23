#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long a, d, b, c, i, j, k, l, m, t, x, y, n, z;
  string s;
  cin >> n;
  long long a1[n], a2[n], a3[n];
  for (i = 0; i < n; i++) cin >> a1[i];
  a2[0] = a1[0];
  a3[n - 1] = a1[n - 1];
  for (i = 1; i < n; i++) a2[i] = a2[i - 1] + a1[i];
  for (i = n - 2; i >= 0; i--) a3[i] = a3[i + 1] + a1[i];
  d = 0;
  for (i = 0; i < n - 1; i++) {
    if (a2[i] == a3[i + 1]) d++;
  }
  cout << d << endl;
  return 0;
}
