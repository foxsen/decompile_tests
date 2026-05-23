#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  a[0] = 1;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  long long mi = 1e9;
  for (int i = 0; i < n; i++) {
    mi = min(a[i], mi);
  }
  mi = 1 - mi;
  set<long long> s;
  for (int i = 0; i < n; i++) {
    a[i] += mi;
    s.insert(a[i]);
  }
  if (s.size() == n && *s.rbegin() == n) {
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
  } else
    cout << -1;
  return 0;
}
