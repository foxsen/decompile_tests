#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int five = 0, zero = 0;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    if (num == 5) {
      five++;
    } else {
      zero++;
    }
  }
  if (zero > 0) {
    if (five > 8) {
      string str((five - (five % 9)), '5');
      for (int i = 0; i < zero; ++i) {
        str.push_back('0');
      }
      cout << str;
    } else {
      cout << 0;
    }
  } else {
    cout << "-1";
  }
}
