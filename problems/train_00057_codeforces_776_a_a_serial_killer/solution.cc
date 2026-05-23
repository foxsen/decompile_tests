#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    i == n ? cout << s1 << " " << s2 : cout << s1 << " " << s2 << endl;
    string f, s;
    cin >> f >> s;
    if (f == s1) {
      s1 = s;
    } else {
      s2 = s;
    }
  }
  cout << s1 << " " << s2 << endl;
  return 0;
}
