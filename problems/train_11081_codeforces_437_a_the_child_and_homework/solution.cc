#include <bits/stdc++.h>
using namespace std;
int a[4];
int main() {
  string s;
  int suma = 0, sumb = 0, sumc = 0, sumd = 0;
  bool o1 = false, o2 = false;
  cin >> s;
  a[0] = suma = s.length() - 2;
  cin >> s;
  a[1] = sumb = s.length() - 2;
  cin >> s;
  a[2] = sumc = s.length() - 2;
  cin >> s;
  a[3] = sumd = s.length() - 2;
  int i, j, re = 0, ve = 0, in = 2;
  for (i = 0; i < 4; i++) {
    re = 0;
    ve = 0;
    for (int j = 0; j < 4; j++) {
      if (i != j && a[i] >= 2 * a[j]) re++;
      if (i != j && a[i] * 2 <= a[j]) ve++;
    }
    if (re == 3) {
      in = i;
      o1 = true;
    }
    if (ve == 3) {
      in = i;
      o2 = true;
    }
  }
  if (o1 && o2) {
    cout << "C";
    return 0;
  }
  if (in == 0) cout << "A";
  if (in == 1) cout << "B";
  if (in == 2) cout << "C";
  if (in == 3) cout << "D";
  return 0;
}
