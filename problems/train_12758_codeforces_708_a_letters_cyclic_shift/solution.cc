#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0;
  int n = s.length();
  while (s[i] == 'a' && i < n) i++;
  if (i == n) {
    s[n - 1] = 'z';
    cout << s << endl;
    return 0;
  }
  while (s[i] != 'a' && i < n) {
    s[i]--;
    i++;
  }
  cout << s << endl;
}
