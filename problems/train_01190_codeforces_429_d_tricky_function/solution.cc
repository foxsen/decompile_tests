#include <bits/stdc++.h>
using namespace std;
template <class T>
T inline sqr(T x) {
  return x * x;
}
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 1e-8;
const int N = 100500;
int a[N];
long long s[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", &a[i]);
  s[0] = a[0];
  for (int i = 1; i <= (int)(n - 1); ++i) s[i] = s[i - 1] + a[i];
  long long ans = sqr(*min_element(a + 1, a + n)) + 1;
  for (int d = 1; d * d < ans; d++) {
    if (clock() > CLOCKS_PER_SEC * 1.8) break;
    for (int i = 0; i < (int)(n - d); ++i) {
      ans = min(ans, sqr(s[i + d] - s[i]) + d * d);
    }
  }
  cout << ans << endl;
  return 0;
}
