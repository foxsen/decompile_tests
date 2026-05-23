#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int dp1[n], dp2[n];
  dp1[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'L') dp1[i + 1] = 0;
    if (s[i] == '=') dp1[i + 1] = dp1[i];
    if (s[i] == 'R') dp1[i + 1] = dp1[i] + 1;
  }
  dp2[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == 'R') dp2[i] = 0;
    if (s[i] == '=') dp2[i] = dp2[i + 1];
    if (s[i] == 'L') dp2[i] = dp2[i + 1] + 1;
  }
  for (int i = 0; i < n; i++) cout << max(dp1[i], dp2[i]) + 1 << " ";
  cout << "\n";
  return 0;
}
