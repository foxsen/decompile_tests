#include <bits/stdc++.h>
using namespace std;
;
long long a[2000001] = {0}, n, m, b[1000001] = {0};
string t;
int main() {
  cin >> n;
  long j = 0;
  for (int k = 1; k; k) {
    if (k == n) break;
    j++;
    k *= 4;
  }
  for (int k = 1; k <= n; ++k) cin >> a[k];
  sort(a + 1, a + n + 1);
  unsigned long long s = a[n], i = a[n], ind = n - 1;
  j -= 1;
  long m = 4;
  while (j >= 0) {
    for (int k = n; k >= n - m + 1; --k) s = s + a[k];
    m = m * 4;
    j--;
  }
  cout << s;
  return 0;
}
