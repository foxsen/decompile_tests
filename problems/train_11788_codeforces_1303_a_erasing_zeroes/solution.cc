#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main() {
  cin >> T;
  while (T--) {
    cin >> s;
    int n = s.length(), c = 0, i = 0;
    while (s[i] != '1' && i < n) i++;
    int st = i;
    i = n - 1;
    while (s[i] != '1' && i >= 0) i--;
    int en = i;
    for (int i = st; i <= en; i++) {
      if (s[i] == '0') c++;
    }
    cout << c << "\n";
  }
}
