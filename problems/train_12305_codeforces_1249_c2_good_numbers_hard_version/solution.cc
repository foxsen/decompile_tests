#include <bits/stdc++.h>
using namespace std;
const long long mxn = 1e5 + 5;
long long INF = 1000000000000000005LL;
void rishabh() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long call(long long n) {
  if (n == 0) return 0;
  if (n % 3 == 2) {
    return call(n / 3 + 1) * 3;
  }
  return max(call(n / 3) * 3, n);
}
int main() {
  rishabh();
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << call(n) << '\n';
  }
}
