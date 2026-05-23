#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4];
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  bool flag = false;
  if (a[0] + a[1] > a[2] && a[0] + a[2] > a[1] && a[1] + a[2] > a[0]) {
    cout << "TRIANGLE";
    return 0;
  } else {
    if (a[0] + a[1] == a[2] || a[1] + a[2] == a[0] || a[0] + a[2] == a[1]) {
      flag = true;
    }
  }
  if (a[0] + a[1] > a[3] && a[0] + a[3] > a[1] && a[3] + a[1] > a[0]) {
    cout << "TRIANGLE";
    return 0;
  } else {
    if (a[0] + a[1] == a[3] || a[3] + a[1] == a[0] || a[0] + a[3] == a[1]) {
      flag = true;
    }
  }
  if (a[0] + a[2] > a[3] && a[0] + a[3] > a[2] && a[3] + a[2] > a[0]) {
    cout << "TRIANGLE";
    return 0;
  } else {
    if (a[0] + a[2] == a[3] || a[3] + a[2] == a[0] || a[0] + a[3] == a[2]) {
      flag = true;
    }
  }
  if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[3] + a[2] > a[1]) {
    cout << "TRIANGLE";
    return 0;
  } else {
    if (a[1] + a[2] == a[3] || a[1] + a[3] == a[2] || a[3] + a[2] == a[1]) {
      flag = true;
    }
  }
  if (flag) {
    cout << "SEGMENT";
  } else {
    cout << "IMPOSSIBLE";
  }
  return 0;
}
