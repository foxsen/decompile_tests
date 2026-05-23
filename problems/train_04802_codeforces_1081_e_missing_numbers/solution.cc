#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, b[200005] = {};
  vector<int> f[200005] = {};
  long long a[100005] = {}, c = 0;
  for (int i = 1; i <= 200000; i++)
    for (int j = i; j <= 200000; j += i) {
      if ((i & 1) == ((j / i) & 1))
        if (i < j / i) f[j].push_back(i);
    }
  for (int i = 1; i <= 200000; i++) reverse(f[i].begin(), f[i].end());
  cin >> n;
  for (int i = 2; i <= n; i++, i++) {
    cin >> a[i];
    bool y = 0;
    for (int j : f[a[i]]) {
      long long d = (a[i] / j - j) / 2;
      a[i - 1] = d * d - c * c;
      if (a[i - 1] > 0) {
        c = (a[i] / j + j) / 2;
        y = 1;
        break;
      }
    }
    if (!y) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}
