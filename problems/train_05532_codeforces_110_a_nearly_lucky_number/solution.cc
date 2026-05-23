#include <bits/stdc++.h>
using namespace std;
long long countDig(long long s) { return floor(log10(s) + 1); }
int main() {
  long long num;
  int luckyNums = 0;
  string n;
  cin >> num;
  int digits = countDig(num);
  n = to_string(num);
  for (int i = 0; i < digits; i++) {
    if (n[i] == '4' || n[i] == '7') luckyNums++;
  }
  if (luckyNums == 4 || luckyNums == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
