#include <bits/stdc++.h>
using namespace std;
int main() {
  string k;
  cin >> k;
  int pos = -1;
  for (int a = 122; a >= 97; a--) {
    for (int b = pos + 1; b < k.length(); b++) {
      if (char(a) == k[b]) {
        cout << k[b];
        pos = b;
      }
    }
  }
  cout << endl;
}
