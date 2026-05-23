#include <bits/stdc++.h>
using namespace std;
int a[10004], b[10004];
int main() {
  int n, m, d = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0, j = 0; i < n && j < m; j++)
    if (b[j] >= a[i]) {
      i++;
      d = i;
    }
  cout << n - d;
  return 0;
}
