#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[1100000];
  long long pos, i, j, len, balance = 0;
  gets(str);
  len = strlen(str);
  for (i = 0; i < len; ++i) {
    if (str[i] == '^') {
      pos = i;
      break;
    }
  }
  for (i = 0; i < len; ++i) {
    if (str[i] == '^' || str[i] == '=') continue;
    balance += (str[i] - '0') * (pos - i);
  }
  if (balance > 0)
    cout << "left" << endl;
  else if (balance < 0)
    cout << "right" << endl;
  else
    cout << "balance" << endl;
  return 0;
}
