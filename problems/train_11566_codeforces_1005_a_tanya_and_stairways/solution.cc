#include <bits/stdc++.h>
using namespace std;
int a[1000], b, c, i, x, n, m, y, k;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    if (a[i] >= a[i + 1]) k++;
  }
  cout << k << endl;
  for (i = 0; i < n; i++) {
    if (a[i] >= a[i + 1]) cout << a[i] << " ";
  }
}
