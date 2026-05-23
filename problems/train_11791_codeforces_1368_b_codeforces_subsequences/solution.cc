#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  long long n;
  cin >> n;
  int p = 1;
  while ((long long)pow(p + 1, 10) <= n) {
    p++;
  }
  int z = 0;
  if ((long long)pow(p, 10) != n) {
    z++;
  }
  string s = "codeforces";
  string ans = "";
  int xp = 0;
  long long zp = (long long)pow(p, 10);
  while (zp < n) {
    xp++;
    zp = (long long)pow(p + z, xp) * (long long)pow(p, 10 - xp);
  }
  for (int i = 0; i < 10; ++i) {
    if (i < xp) {
      for (int j = 0; j < p + z; ++j) {
        ans += s[i];
      }
    } else {
      for (int j = 0; j < p; ++j) {
        ans += s[i];
      }
    }
  }
  cout << ans;
}
