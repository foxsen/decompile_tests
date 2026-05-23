#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s;
    long long int t1 = 0, t2 = 0, th = -1, c1 = 0, c2 = 0;
    for (long long int i = 0; i < s.size(); i++) {
      if (i % 2 == 0) {
        if (s[i] == '1' || s[i] == '?') t1 += 1;
        c1 += 1;
      } else {
        if (s[i] == '1') t2 += 1;
        c2 += 1;
      }
      if (t2 + 5 - c2 < t1) {
        if (th == -1)
          th = i;
        else
          th = min(i, th);
        break;
      }
    }
    t1 = 0;
    t2 = 0;
    c1 = 0;
    c2 = 0;
    for (long long int i = 0; i < s.size(); i++) {
      if (i % 2 == 0) {
        if (s[i] == '1') t1 += 1;
        c1 += 1;
      } else {
        if (s[i] == '1' || s[i] == '?') t2 += 1;
        c2 += 1;
      }
      if (t1 + 5 - c1 < t2) {
        if (th == -1)
          th = i;
        else
          th = min(i, th);
        break;
      }
    }
    if (th == -1) th = 9;
    cout << th + 1 << '\n';
  }
}
