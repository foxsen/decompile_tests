#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(20);
  int n;
  cin >> n;
  long long res, t;
  cin >> res;
  for (int i = 0; i < (int)(n - 1); ++i) {
    cin >> t;
    res = gcd(res, t);
  }
  int ans = 0;
  for (int i = 1; i <= (int)(sqrt(res)); ++i) {
    if (res % i == 0) ans += 2;
  }
  if (((long long)sqrt(res)) * ((long long)sqrt(res)) == res) ans--;
  cout << ans;
  return 0;
}
