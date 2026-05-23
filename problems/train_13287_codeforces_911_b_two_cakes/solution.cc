#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, a, b;
  cin >> n >> a >> b;
  if (n == a + b) {
    cout << 1 << endl;
    return 0;
  }
  long long int val = 0;
  for (long long int i = 1; i < n; i++) {
    val = max(val, min(a / i, b / (n - i)));
  }
  cout << val;
  return 0;
}
