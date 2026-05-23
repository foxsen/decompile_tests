#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
int even(int x) {
  if (x <= 2) return x;
  return (x & 1) ^ 1;
}
int odd(int x) {
  if (x <= 3) return x & 1;
  if (x == 4) return 2;
  if (x & 1) return 0;
  int cnt = odd(x / 2);
  if (cnt == 1) return 2;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int n, k, ans = 0;
  cin >> n >> k;
  k &= 1;
  for (int i = 0, j; i < n; i++) {
    cin >> j;
    ans ^= (k & 1) ? odd(j) : even(j);
  }
  string out = (ans) ? "Kevin" : "Nicky";
  cout << out << endl;
  return 0;
}
