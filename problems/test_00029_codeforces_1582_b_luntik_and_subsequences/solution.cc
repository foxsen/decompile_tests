#include <bits/stdc++.h>
using namespace std;
void fastInOut() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  int a[n];
  long long ones = 0, zeros = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1)
      ones++;
    else if (a[i] == 0)
      zeros++;
  }
  cout << ((ones) * (1ll << zeros)) << endl;
}
int main(int argc, char const* argv[]) {
  fastInOut();
  int tst = 1;
  cin >> tst;
  while (tst--) {
    solve();
  }
  return 0;
}
