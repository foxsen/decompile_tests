#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  unsigned int t11, t12;
  unsigned int t21, t22;
  cin >> c;
  t11 = (c - 48) * 10;
  cin >> c;
  t11 += c - 48;
  cin >> c >> c;
  t12 = (c - 48) * 10;
  cin >> c;
  t12 += c - 48;
  cin >> c;
  t21 = (c - 48) * 10;
  cin >> c;
  t21 += c - 48;
  cin >> c >> c;
  t22 = (c - 48) * 10;
  cin >> c;
  t22 += c - 48;
  int t31, t32;
  t31 = t11 - t21;
  t32 = t12 - t22;
  if (t32 < 0) {
    t32 = 60 + t32;
    t31--;
  }
  if (t31 < 0) t31 = 24 + t31;
  if (t31 < 10) cout << "0";
  cout << t31 << ":";
  if (t32 < 10) cout << "0";
  cout << t32;
  return 0;
}
