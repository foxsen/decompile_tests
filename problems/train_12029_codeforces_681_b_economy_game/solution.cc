#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000000000;
const long long HOUSE_PRICE = 1234567LL;
const long long CAR_PRICE = 123456LL;
const long long COMPUTER_PRICE = 1234LL;
long long N;
void init() { cin >> N; }
bool isDivisible(long long a, long long b, long long c) {
  if (c % a == 0 or c % b == 0) return true;
  if ((c & 1) == 1) return false;
  const long long m1 = 2201LL;
  const long long m2 = -22LL;
  const long long k1 = 617LL;
  const long long k2 = -61728LL;
  long long x0 = (m2 * c) / 2LL;
  long long y0 = (m1 * c) / 2LL;
  while (y0 >= 0) {
    if (x0 >= 0) return true;
    x0 += k1;
    y0 += k2;
  }
  return false;
}
bool isPossible() {
  for (long long a = 0; a * HOUSE_PRICE <= N; a++) {
    if (isDivisible(CAR_PRICE, COMPUTER_PRICE, N - a * HOUSE_PRICE))
      return true;
  }
  return false;
}
void solve() { cout << (isPossible() ? "YES" : "NO") << "\n"; }
int main() {
  init();
  solve();
  return 0;
}
