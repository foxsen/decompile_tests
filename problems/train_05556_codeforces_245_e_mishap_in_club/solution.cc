#include <bits/stdc++.h>
using namespace std;
signed main() {
  string s;
  cin >> s;
  long long maxx = 0, minn = 0;
  long long d = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == '+')
      d++;
    else
      d--;
    maxx = max(maxx, d);
    minn = min(minn, d);
  }
  cout << maxx - minn << endl;
}
