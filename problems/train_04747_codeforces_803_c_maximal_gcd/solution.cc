#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, gcd = 0;
  cin >> n >> k;
  if (k > 141420) {
    cout << "-1" << endl;
    return 0;
  }
  long long temp = sqrt(n);
  long long summ = k * (k + 1) / 2;
  for (long long i = 1; i <= temp; i++)
    if (n % i == 0) {
      if (i >= summ) {
        gcd = n / i;
        break;
      } else if (n / i >= summ)
        gcd = i;
    }
  if (!gcd) {
    cout << "-1" << endl;
    return 0;
  }
  for (long long i = 1; i < k; i++) cout << i * gcd << " ";
  cout << gcd * (n / gcd - k * (k - 1) / 2) << endl;
}
