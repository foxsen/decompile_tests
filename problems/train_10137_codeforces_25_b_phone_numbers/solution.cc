#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  cin >> n;
  int i = 1, j;
  for (j = 0; j < n; j++) i *= 10;
  cin >> s;
  bool flag = 0;
  if (n % 2 == 1) {
    flag = 1;
    n -= 3;
  } else
    n -= 2;
  for (j = 0; j < n; j += 2) {
    for (int jj = j; jj < j + 2; jj++) cout << s[jj];
    cout << '-';
  }
  n = s.size();
  if (flag)
    cout << s[n - 3] << s[n - 2] << s[n - 1];
  else
    cout << s[n - 2] << s[n - 1];
  return 0;
}
