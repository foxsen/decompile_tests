#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s1, s2, s3;
  cin >> s1;
  long long f = 0, l1;
  for (long long x = 0; x < s1.length(); x++) {
    if (s1[x] == '.') {
      f = 1;
      continue;
    }
    if (f == 0)
      s2 += s1[x];
    else
      s3 += s1[x];
  }
  l1 = s2.length();
  if (s2[l1 - 1] - 48 < 9) {
    if (s3[0] - 48 >= 5) s2[l1 - 1] += 1;
  } else {
    cout << "GOTO Vasilisa.";
    return;
  }
  cout << s2;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}
