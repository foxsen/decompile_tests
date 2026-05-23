#include <bits/stdc++.h>
using namespace std;
long long power(long b, long k) {
  long long product = 1;
  if (k == 0) {
    product = 1;
  } else if (k == 1) {
    product = b;
  } else {
    product = power(b, k / 2);
    product = product * product;
    if (k % 2) {
      product = product * b;
    }
  }
  return product;
}
int main() {
  long long b, k, sum = 0, m;
  cin >> b >> k;
  int arr[k];
  for (int i = 0; i < k; i++) {
    cin >> arr[i];
  }
  m = k - 1;
  for (long long i = 0; i < k; i++) {
    sum = sum + arr[i] * (power(b, m));
    if (m == 0) {
      m = 0;
    } else {
      m = m - 1;
    }
  }
  if (sum % 2 == 0) {
    cout << "even";
  } else {
    cout << "odd";
  }
  return 0;
}
