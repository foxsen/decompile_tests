#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int value, count = 9;
  cin >> value;
  if (value < 10) {
    cout << 9;
    return 0;
  }
  count = count + 10 - (value % 10);
  value = value / 10;
  while (value >= 10) {
    count = count + 9 - (value % 10);
    value = value / 10;
  }
  cout << count;
  return 0;
}
