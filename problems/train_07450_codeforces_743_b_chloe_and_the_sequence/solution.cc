#include <bits/stdc++.h>
using namespace std;
const int mod = 7 + (int)1e9;
const int N = 1 + 1e0;
long long f(long long n, long long k) {
  while (n--) {
    long long mid = 1LL << n;
    if (k == mid) {
      return n + 1;
    } else if (k > mid) {
      k -= mid;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  cout << f(n, k) << endl;
  return 0;
}
