#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int co = 0;
  int j = 0;
  string val;
  cin >> val;
  while (j < n) {
    if (val[j] == '1') {
      co++;
      j++;
    } else {
      co++;
      break;
    }
  }
  cout << co;
  return 0;
}
