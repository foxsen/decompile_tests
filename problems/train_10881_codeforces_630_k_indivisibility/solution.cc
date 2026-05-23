#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int main() {
  long long int n;
  cin >> n;
  long long int m = n;
  m -= (n / 2);
  m -= (n / 3);
  m -= (n / 5);
  m -= (n / 7);
  m += (n / 6);
  m += (n / 10);
  m += (n / 14);
  m += (n / 15);
  m += (n / 21);
  m += (n / 35);
  m -= (n / 30);
  m -= (n / 70);
  m -= (n / 42);
  m -= (n / 105);
  m += (n / 210);
  cout << m << '\n';
  return 0;
}
