#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
void solve1() {
  long long n, t;
  cin >> n;
  long long sum = 0;
  for (long long i = (long long)0; i < (long long)(n); i++) {
    cin >> t;
    sum += t;
  }
  if (sum % n == 0)
    cout << n;
  else
    cout << n - 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve1();
  }
  return 0;
}
