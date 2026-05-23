#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long a[n];
  long long sum = 0;
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < (n / 2); i++) {
    sum += (a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1]);
  }
  cout << sum;
  return 0;
}
