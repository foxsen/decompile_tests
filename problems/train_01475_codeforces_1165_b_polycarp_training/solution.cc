#include <bits/stdc++.h>
using namespace std;
const long long prime = 1e9 + 7;
const long long maxN = 2e5 + 5;
const long double pi = 3.1415926536;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, a[maxN], ans = 0, mn = 1;
  cin >> n;
  for (long long i = (long long)(1); i <= (long long)(n); i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (long long i = (long long)(1); i <= (long long)(n); i++) {
    if (mn <= a[i]) {
      mn++;
      ans++;
    }
  }
  cout << ans;
  return 0;
}
