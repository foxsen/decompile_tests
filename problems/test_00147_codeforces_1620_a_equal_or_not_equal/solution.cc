#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, a;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    a = 0;
    n = s.length();
    for (int i = 0; i < n; i++)
      if (s[i] == 'N') a++;
    if (a == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
