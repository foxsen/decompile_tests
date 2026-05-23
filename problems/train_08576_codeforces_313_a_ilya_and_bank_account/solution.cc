#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int cash;
  cin >> cash;
  if (cash > 0) {
    cout << cash << endl;
    exit(0);
  } else {
    int digsl, digl;
    digl = (abs(cash)) % 10;
    digsl = (abs(cash / 10)) % 10;
    if (digl < digsl) {
      cash = cash / 100;
      cash = cash * 10 - digl;
    } else {
      cash = cash / 10;
    }
    if (cash > 0) {
      cash *= -1;
    }
    cout << cash << endl;
  }
  return 0;
}
