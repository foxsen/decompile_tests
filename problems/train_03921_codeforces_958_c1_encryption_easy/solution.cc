#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, i, j, k, l, n, m, x, y;
  cin >> n >> m;
  long long int v[n + 8], s[n + 8];
  k = 0;
  l = 0;
  x = 0;
  j = 0;
  for (i = 0; i < n; i++) {
    cin >> s[i];
    l += s[i];
  }
  for (i = 0; i < n - 1; i++) {
    k += s[i];
    a = k % m;
    b = l - k;
    b = b % m;
    c = b + a;
    x = max(x, c);
  }
  cout << x;
}
