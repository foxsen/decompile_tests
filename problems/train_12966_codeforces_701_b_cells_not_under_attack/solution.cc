#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  set<long long> x, y;
  int m = n;
  long long ans[k];
  for (int i = 0, a, b; i < k; i++) {
    cin >> a >> b;
    if (x.count(a - 1) == 0) n--;
    if (y.count(b - 1) == 0) m--;
    x.insert(a - 1);
    y.insert(b - 1);
    ans[i] = n * m;
  }
  for (int i = 0; i < k; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
