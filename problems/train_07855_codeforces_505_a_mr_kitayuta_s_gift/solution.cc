#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, a;
  cin >> s;
  for (int i = 0; i <= s.length(); i++) {
    for (int b = 'a'; b <= 'z'; b++) {
      a = s.substr(0, i) + ((char)b) + s.substr(i, s.size());
      if (a == string(a.rbegin(), a.rend())) {
        cout << a << endl;
        return 0;
      }
    }
  }
  cout << "NA" << endl;
  return 0;
}
