#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[8];
  int i, j, cnta = 0, cntb = 0;
  for (i = 0; i < 8; i++) {
    cin >> s[i];
    for (j = 0; j < 8; j++) {
      if (s[i][j] == 'Q') cnta += 9;
      if (s[i][j] == 'R') cnta += 5;
      if (s[i][j] == 'B') cnta += 3;
      if (s[i][j] == 'N') cnta += 3;
      if (s[i][j] == 'P') cnta += 1;
      if (s[i][j] == 'q') cntb += 9;
      if (s[i][j] == 'r') cntb += 5;
      if (s[i][j] == 'b') cntb += 3;
      if (s[i][j] == 'n') cntb += 3;
      if (s[i][j] == 'p') cntb += 1;
    }
  }
  if (cnta > cntb)
    cout << "White"
         << "\n";
  else if (cntb > cnta)
    cout << "Black"
         << "\n";
  else
    cout << "Draw";
  return 0;
}
