#include <bits/stdc++.h>
using namespace std;
int n, c;
bool b[10];
string k;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    if (k == "purple") b[0] = 1;
    if (k == "red") b[4] = 1;
    if (k == "green") b[1] = 1;
    if (k == "blue") b[2] = 1;
    if (k == "orange") b[3] = 1;
    if (k == "yellow") b[5] = 1;
  }
  cout << 6 - n << endl;
  for (int i = 0; i < 6; i++) {
    if (b[i] == 0) {
      if (i == 0) cout << "Power" << endl;
      if (i == 1) cout << "Time" << endl;
      if (i == 2) cout << "Space" << endl;
      if (i == 3) cout << "Soul" << endl;
      if (i == 4) cout << "Reality" << endl;
      if (i == 5) cout << "Mind" << endl;
    }
  }
  return 0;
}
