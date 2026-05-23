#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long x = a[n - 1], y = a[n - 2], c = 0, sum = 0;
  long long noti = m / (k + 1);
  sum = noti * x * k;
  sum += noti * y;
  long long rem = m % (k + 1);
  sum += rem * x;
  cout << sum << endl;
}
