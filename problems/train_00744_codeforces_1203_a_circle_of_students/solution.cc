#include <bits/stdc++.h>
using namespace std;
long long int cnt = 0;
long long int n, m;
long long int h1[100005], h2[100007];
int main() {
  long long int i, j, k, l, n, m;
  long long int q;
  cin >> q;
  while (q--) {
    cin >> n;
    long long int a[n], t = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) t = i;
    }
    long long int u = 1, nm = 0;
    for (i = t; i < n; i++, u++)
      if (a[i] == u) {
      } else
        nm++;
    for (i = 0; i < t; i++, u++)
      if (a[i] == u) {
      } else
        nm++;
    long long int ut = 0;
    u = 1;
    for (i = t; i >= 0; i--, u++)
      if (a[i] == u) {
      } else
        ut++;
    for (i = n - 1; i > t; i--, u++)
      if (a[i] == u) {
      } else
        ut++;
    if (nm > 0 && ut > 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
