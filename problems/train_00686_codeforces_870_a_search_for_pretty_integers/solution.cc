#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[100], b[100];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b, b + m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        cout << a[i] << '\n';
        return 0;
      }
    }
  }
  if (a[0] > b[0]) {
    swap(a[0], b[0]);
  }
  cout << a[0] << b[0] << '\n';
}
