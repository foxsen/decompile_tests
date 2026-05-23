#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int x = 0;
  if (n % 4 == 1)
    x = 1;
  else if (n % 4 == 3)
    x = 2;
  else if (n % 4 == 2)
    x = 3;
  else
    x = 4;
  if (x == 1)
    cout << "0 A";
  else if (x == 2)
    cout << "2 A";
  else if (x == 3)
    cout << "1 B";
  else
    cout << "1 A";
  return 0;
}
