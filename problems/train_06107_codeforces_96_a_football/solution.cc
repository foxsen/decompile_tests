#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  int c = 0, b = 0;
  cin >> a;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '1') {
      c = 0;
      b++;
      if (b >= 7 || c >= 7) {
        cout << "YES";
        break;
      }
    } else {
      b = 0;
      c++;
      if (b >= 7 || c >= 7) {
        cout << "YES";
        break;
      }
    }
  }
  if (b >= 7 || c >= 7) {
  } else {
    cout << "NO";
  }
  return 0;
}
