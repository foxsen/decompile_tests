#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> val(n);
  for (auto &i : val) cin >> i;
  int a, b;
  long long res = 0;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    long long t = 0;
    for (int j = a - 1; j < b; ++j) t += val[j];
    if (t > 0) res += t;
  }
  cout << res << endl;
  return 0;
}
