#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, i, l, q = 0, r = 0, m, p = 0, z, f, w = 100;
  long long int k = 0, j = 0, t = 0;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = 0; i < 100; i++) {
    for (j = n - 1; j > 0; j--) {
      if (a[j] > a[j - 1]) a[j] -= a[j - 1];
    }
    sort(a, a + n);
  }
  for (i = 0; i < n; i++) k += a[i];
  cout << k;
}
