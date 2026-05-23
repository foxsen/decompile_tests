#include <bits/stdc++.h>
using namespace std;
inline void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline void AYUSH() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  fast();
  AYUSH();
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long odd = ((n % 2 == 0) ? n - 1 : n), eve = n - n % 2, x = 6;
    if (n < 4) {
      cout << -1 << endl;
      continue;
    }
    while (odd >= 1) {
      cout << odd << " ";
      odd -= 2;
    }
    cout << 4 << " " << 2 << " ";
    while (x <= eve) {
      cout << x << " ";
      x += 2;
    }
    cout << endl;
  }
}
