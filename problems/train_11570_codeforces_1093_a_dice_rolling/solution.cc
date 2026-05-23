#include <bits/stdc++.h>
using namespace std;
void func() {
  long long int n;
  cin >> n;
  long long int count = 0;
  while (n >= 7) {
    count++;
    n -= 7;
  }
  if (n) count++;
  cout << count << '\n';
}
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    func();
  }
  return 0;
}
