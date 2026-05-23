#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s1 = 0, s2 = 0;
  int x[105], y[105];
  bool pos = false;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    s1 += x[i];
    s2 += y[i];
    if (x[i] % 2 != y[i] % 2) {
      pos = true;
    }
  }
  s1 = s1 % 2;
  s2 = s2 % 2;
  if (s1 == 0 && s2 == 0) {
    cout << "0" << endl;
  } else if (s1 == 1 && s2 == 1) {
    if (pos)
      cout << "1" << endl;
    else
      cout << "-1" << endl;
  } else {
    cout << "-1" << endl;
  }
}
