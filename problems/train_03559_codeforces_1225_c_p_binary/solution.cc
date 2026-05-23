#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, p;
  cin >> n >> p;
  long long int f = 0, g = 0;
  for (long long int i = 1; i <= 10000; i++) {
    long long int a = n - (p * i);
    if (a == 1 && i != 1) continue;
    long long int x = 0;
    for (long long int j = 1; j <= i; j++) {
      if (a <= 0) break;
      long long int q = log2(a);
      x = x + pow(2, q);
      a = a - pow(2, q);
      if (a == 0) {
        if (i <= x) f = 1;
        break;
      }
    }
    if (f == 1) {
      cout << i;
      g = 1;
      break;
    }
  }
  if (g == 0) cout << -1;
  return 0;
}
