#include <bits/stdc++.h>
using namespace std;
const int M = 1000 + 5;
int main() {
  int n, m;
  cin >> n >> m;
  int Lborder = 1;
  int Rborder = n;
  string s[4];
  int x;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> s[j];
    }
    cin >> x;
    if (s[2] == "left") {
      if (x - 1 < Rborder) Rborder = x - 1;
    } else {
      if (x + 1 > Lborder) Lborder = x + 1;
    }
  }
  if (Lborder <= Rborder) {
    cout << Rborder - Lborder + 1 << endl;
  } else {
    cout << "-1" << endl;
  }
  return 0;
}
