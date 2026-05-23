#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> n >> s;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cnt0++;
    } else
      cnt1++;
  }
  if (cnt0 != cnt1) {
    cout << "1" << endl;
    cout << s << endl;
  } else {
    cout << "2" << endl;
    cout << s[0] << " " << s.substr(1, n);
  }
  return 0;
}
