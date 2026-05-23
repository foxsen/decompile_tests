#include <bits/stdc++.h>
using namespace std;
int n, col = 0, o[100010], c[100010];
int a[100010];
int main() {
  cin >> n;
  int max = 0;
  for (int i = 0; i <= 100000; i++) {
    o[i] = 0;
    c[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > max) max = a[i];
    o[a[i]]++;
  }
  for (int i = 2; i <= max; i++) {
    if (o[i] > o[i - 1]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << o[1] << endl;
  c[a[0]]++;
  cout << c[a[0]];
  for (int i = 1; i < n; i++) {
    c[a[i]]++;
    cout << " " << c[a[i]];
  }
  cout << endl;
  return 0;
}
