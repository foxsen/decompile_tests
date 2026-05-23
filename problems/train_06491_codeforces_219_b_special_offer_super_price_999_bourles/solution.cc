#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;
const int N = 1e8 + 7;
const int INF = 1000000009;
const int MOD = 1000000009;
const double eps = 1e-2;
long long po(long long x, long long y) {
  if (y == 0) {
    return 1;
  }
  long long sq = po(x, y / 2);
  sq *= sq;
  sq = sq % MOD;
  if (y % 2 != 0) {
    sq *= x;
    sq = sq % MOD;
  }
  return sq;
}
long long a[19];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long num, y, tn = 10;
  cin >> num >> y;
  long long t = num, s = 0;
  while (t > 0) {
    if (t % 10 == 9) {
      s++;
    } else {
      break;
    }
    t /= 10;
  }
  for (long long k = 0; k < 17; k++) {
    a[k] = num - (num % tn) - 1;
    tn *= 10;
  }
  for (long long i = 16; i >= 0; i--) {
    long long x = num - a[i];
    if (s >= i + 1) {
      cout << max(a[i], num) << endl;
      return 0;
    }
    if (x <= y && x >= 0) {
      cout << a[i] << endl;
      return 0;
    }
  }
  cout << num << endl;
}
