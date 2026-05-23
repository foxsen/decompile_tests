#include <bits/stdc++.h>
using namespace std;
void mian() {
  long long s, n, k;
  cin >> s >> n >> k;
  cout << (k > s || n / k * 2 * k + n % k <= s && k != s ? "NO\n" : "YES\n");
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) mian();
  return 0;
}
