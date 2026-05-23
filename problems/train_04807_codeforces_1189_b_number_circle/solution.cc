#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, n, i;
  cin >> n;
  long long int a[n], sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  bool ok = false;
  ;
  swap(a[n - 1], a[n - 2]);
  if (a[n - 2] >= a[n - 1] + a[n - 3]) ok = true;
  if (ok)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (long long int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
