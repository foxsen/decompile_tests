#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, n1, n2, n3, n4, n6, n12;
  string s;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    k = 0;
    n1 = n2 = n3 = n4 = n6 = n12 = 0;
    for (j = 0; j < 12; j++) {
      if (s[j] == 'X') {
        n1++;
        n12++;
        if (j < 6 && (s[j + 6] == 'X')) n2++;
        if (j < 4 && (s[j + 4] == 'X') && (s[j + 8] == 'X')) n3++;
        if (j < 3 && (s[j + 3] == 'X') && (s[j + 6] == 'X') &&
            (s[j + 9] == 'X'))
          n4++;
        if (j < 2 && (s[j + 2] == 'X') && (s[j + 4] == 'X') &&
            (s[j + 6] == 'X') && (s[j + 8] == 'X') && (s[j + 10] == 'X'))
          n6++;
      }
    }
    if (n1 > 0) k++;
    if (n2 > 0) k++;
    if (n3 > 0) k++;
    if (n4 > 0) k++;
    if (n6 > 0) k++;
    if (n12 == 12) k++;
    cout << k;
    if (k > 0) {
      if (n1 > 0) cout << " 1x12";
      if (n2 > 0) cout << " 2x6";
      if (n3 > 0) cout << " 3x4";
      if (n4 > 0) cout << " 4x3";
      if (n6 > 0) cout << " 6x2";
      if (n12 == 12) cout << " 12x1";
    }
    cout << endl;
  }
  return 0;
}
