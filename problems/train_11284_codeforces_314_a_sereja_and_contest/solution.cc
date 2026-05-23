#include <bits/stdc++.h>
using namespace std;
long long n, k, a, c, sum;
int j = 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  c = n;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    if ((sum - (c - j) * (j - 1) * a) < k) {
      cout << i << '\n';
      --c;
    } else {
      sum += a * (j - 1);
      ++j;
    }
  }
}
