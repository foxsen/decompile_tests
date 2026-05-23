#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, i, j, k, l;
  cin >> n >> m;
  long long int a[m + 2];
  for (i = 0; i < m; i++) {
    cin >> a[i];
  }
  long long int ct = 0;
  for (i = 0; i < m; i++) {
    long long int cc = a[i];
    long long int vc = 0;
    for (j = 0; j < i; j++) {
      if (a[j] < cc) vc++;
    }
    ct += vc;
  }
  cout << ct << endl;
}
int main() {
  int t, tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
