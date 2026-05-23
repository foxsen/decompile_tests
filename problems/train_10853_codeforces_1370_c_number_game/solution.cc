#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> mp;
void Prime(long long int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long int p = 2; p <= n; p++)
    if (prime[p]) mp[p]++;
}
long long int smallestDivisor(long long int n) {
  for (long long int i = 3; i <= n / 2; i += 2) {
    if (n % i == 0) return i;
  }
  return n;
}
bool isPrime(long long int n) {
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << "FastestFinger" << endl;
    return;
  }
  if (n == 2) {
    cout << "Ashishgup" << endl;
    return;
  }
  if (n % 2 != 0) {
    cout << "Ashishgup" << endl;
    return;
  }
  if ((n & (n - 1)) == 0) {
    cout << "FastestFinger" << endl;
    return;
  }
  if (isPrime(n / 2)) {
    cout << "FastestFinger" << endl;
    return;
  }
  cout << "Ashishgup" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
