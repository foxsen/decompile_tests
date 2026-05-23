#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string t, s;
  cin >> n >> s;
  t = s;
  sort(s.begin(), s.end());
  int ret = (1 << 21);
  for (int i = 0; i < s.length() + 1; i++) {
    int dif = 0;
    for (int i = 0; i < s.length(); i++) {
      if (t[i] != s[i]) dif++;
    }
    ret = min(ret, dif);
    rotate(s.begin(), s.begin() + 1, s.end());
  }
  cout << ret / 2 << endl;
}
