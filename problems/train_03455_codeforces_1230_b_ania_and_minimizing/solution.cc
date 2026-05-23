#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (n == 1 && k > 0) {
    cout << 0 << endl;
  } else if (k == 0) {
    cout << s << endl;
  } else {
    int i = 0;
    int j = 1;
    if (s[0] != '1') {
      s[0] = '1';
      k--;
    }
    while (i < k && j < n) {
      if (s[j] == '0') {
        j++;
        continue;
      }
      s[j] = '0';
      i++;
      j++;
    }
    cout << s << endl;
  }
  return 0;
}
