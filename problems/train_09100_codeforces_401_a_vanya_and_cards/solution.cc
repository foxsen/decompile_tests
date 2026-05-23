#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, sum = 0, l;
  cin >> n >> x;
  long long* a = new long long[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sum = abs(sum);
  l = sum / x;
  if (sum % x != 0) l++;
  cout << l << endl;
  return 0;
}
