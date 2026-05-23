#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s[13] = {"0",       "January",  "February", "March",  "April",
                  "May",     "June",     "July",     "August", "September",
                  "October", "November", "December"};
  string a;
  cin >> a;
  int n, x;
  cin >> n;
  for (int i = 0; i < 13; i++)
    if (a == s[i]) {
      x = i;
      break;
    }
  int b = n % 12;
  if (b == 0)
    cout << s[x] << endl;
  else if (x + b > 12) {
    b = (x + b) % 12;
    cout << s[b] << endl;
  } else
    cout << s[x + b] << endl;
}
