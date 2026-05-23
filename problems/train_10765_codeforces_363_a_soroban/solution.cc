#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(time(NULL));
  int x;
  string s[100];
  cin >> x;
  s[0] = "O-|-OOOO";
  s[1] = "O-|O-OOO";
  s[2] = "O-|OO-OO";
  s[3] = "O-|OOO-O";
  s[4] = "O-|OOOO-";
  s[5] = "-O|-OOOO";
  s[6] = "-O|O-OOO";
  s[7] = "-O|OO-OO";
  s[8] = "-O|OOO-O";
  s[9] = "-O|OOOO-";
  if (x == 0) {
    cout << s[0];
    exit(0);
  }
  while (x) {
    cout << s[x % 10] << endl;
    x /= 10;
  }
  return 0;
}
