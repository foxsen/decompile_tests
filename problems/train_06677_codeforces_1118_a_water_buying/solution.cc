#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (0) {
  };
  int q;
  cin >> q;
  long long n;
  int a, b;
  long long out = 0;
  while (q--) {
    cin >> n >> a >> b;
    if (a * 2 <= b) {
      out = (long long)a * n;
    } else {
      out = (long long)b * (n / (long long)2);
      if (n % (long long)2 == 1) {
        out += a;
      }
    }
    cout << out << "\n";
  }
  while (0) {
  };
  return 0;
}
