#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 0;
  cin >> n;
  double R = n;
  long long tmp = n, k;
  for (long long i = 1; i <= n; i++) {
    double r = i;
    k = (long long)sqrt(R * R - r * r);
    ans += (tmp == k ? 1 : tmp - k);
    tmp = k;
  }
  if (n == 0)
    cout << 1 << endl;
  else
    cout << ans * 4 << endl;
  return 0;
}
