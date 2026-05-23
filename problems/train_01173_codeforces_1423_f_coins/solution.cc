#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  long long n, k;
  cin >> n >> k;
  long long tot = 0;
  long long sumPos = 0;
  for (int _ = 0; _ < (k); ++_) {
    long long pos, num;
    cin >> pos >> num;
    pos--;
    sumPos += pos * num;
    sumPos %= n;
    tot += num;
  }
  if (tot > n) {
    cout << -1 << endl;
  } else if (tot < n) {
    cout << 1 << endl;
  } else {
    long long expected = (n - 1) * n / 2;
    if (expected % n == sumPos)
      cout << 1 << endl;
    else
      cout << -1 << endl;
  }
}
