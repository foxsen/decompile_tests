#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, d = 0;
    cin >> n;
    string s;
    vector<char> a, b;
    cin >> s;
    for (i = 0; i < n; i++) {
      if (s[i] == '2' && d == 0) {
        a.push_back('1');
        b.push_back('1');
      } else if (s[i] == '2') {
        a.push_back('0');
        b.push_back('2');
      } else if (s[i] == '1' && d == 0) {
        d = 1;
        a.push_back('1');
        b.push_back('0');
      } else if (s[i] == '1') {
        a.push_back('0');
        b.push_back('1');
      } else {
        a.push_back('0');
        b.push_back('0');
      }
    }
    for (i = 0; i < n; i++) cout << a[i];
    cout << "\n";
    for (i = 0; i < n; i++) cout << b[i];
    cout << "\n";
  }
  return 0;
}
