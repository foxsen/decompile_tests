#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n;
long long a[N], b[N], c[N];
bool check() {
  bool check = 0;
  for (long long i = 1; i <= n; i++)
    if (a[i] != b[i]) check = 1;
  bool check2 = 0;
  for (long long i = 1; i <= n; i++)
    if (a[i] != c[i]) check2 = 1;
  return check & check2;
}
void work() {
  for (long long i = 1; i <= n - 1; i++) {
    if (a[i] != a[i + 1]) {
      swap(a[i], a[i + 1]);
      if (check()) {
        cout << i << " " << i + 1;
        exit(0);
      }
      swap(a[i], a[i + 1]);
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    c[i] = b[i];
  }
  sort(b + 1, b + n + 1);
  sort(c + 1, c + n + 1, greater<long long>());
  work();
  cout << "-1";
  return 0;
}
