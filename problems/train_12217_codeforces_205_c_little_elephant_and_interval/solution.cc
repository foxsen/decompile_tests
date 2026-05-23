#include <bits/stdc++.h>
using namespace std;
long long calc(long long n) {
  if (n < 10) {
    return n;
  }
  long long ans = n / 10 + 9;
  long long l = n % 10;
  while (n > 9) {
    n = n / 10;
  }
  if (n > l) {
    ans--;
  }
  return ans;
}
int main() {
  long long l, r;
  cin >> l >> r;
  cout << calc(r) - calc(l - 1);
}
