#include <bits/stdc++.h>
int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int MOD = 1e9 + 7, N = 2e5 + 5;
const double pi = acos(-1);
using namespace std;
bool prime(long long n) {
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  if (n == 1 or prime(n)) return cout << 1 << endl << 0, 0;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      long long tmp = n / i;
      for (long long j = 2; j * j <= tmp; j++) {
        if (tmp % j == 0) return cout << 1 << endl << i * j, 0;
      }
      return cout << 2, 0;
    }
  }
  return 0;
}
