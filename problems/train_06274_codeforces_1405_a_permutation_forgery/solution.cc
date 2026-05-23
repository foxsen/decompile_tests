#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t, n, i;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int s[n];
    for (i = 0; i < n; i++) cin >> s[i];
    for (i = n - 1; i >= 0; i--) cout << s[i] << " ";
    cout << '\n';
  }
  return 0;
}
