#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e6 + 3;
int n;
int main() {
  cin >> n;
  long long res = 1;
  for (int i = 0; i < n - 1; ++i) res = (res * 3) % MOD;
  cout << res << endl;
  return 0;
}
