#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MXN = 15;
const int MXC = 1e5 + 5;
long long n, a[MXN];
bool check(long long n) {
  long long x;
  for (int i = 0; i < 10; i++) a[i] = 0;
  while (n != 0) {
    x = n % 10;
    n /= 10;
    a[x]++;
  }
  for (int i = 0; i < 10; i++) {
    if (a[i] > 1) return false;
  }
  return true;
}
int main() {
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  };
  cin >> n;
  n++;
  while (!check(n)) {
    n++;
  }
  cout << n << '\n';
  return 0;
}
