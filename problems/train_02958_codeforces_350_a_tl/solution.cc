#include <bits/stdc++.h>
using namespace std;
long long int d[10], e[10];
int po(int n, int exp) {
  int prod = 1;
  for (int i = 0; i < exp; i++) prod = (prod * n);
  return prod;
}
int main() {
  long long int i, j, k, n, m, s = 0, t;
  cin >> n >> m;
  long long int a[n], b[m], c[n];
  set<long long int> f, g;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  k = max(2 * a[0], a[n - 1]);
  t = b[0];
  if (k >= t)
    cout << "-1";
  else
    cout << k;
}
