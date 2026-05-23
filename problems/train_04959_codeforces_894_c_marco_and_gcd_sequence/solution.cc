#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int n;
  int s[4005];
  cin >> n;
  cin >> s[0];
  int k = s[0];
  for (int i = 1; i < n; i++) {
    cin >> s[i];
    k = gcd(k, s[i]);
    if (k < s[0]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  cout << 2 * n << endl;
  for (int i = 0; i < n; i++) {
    cout << s[i] << " " << k;
    if (i != n - 1) cout << " ";
  }
  cout << endl;
  return 0;
}
